#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50, LOGN = 20, INF = (int)1e9;
typedef pair<int, int> P;
typedef long long ll;

int jp[LOGN][N];
int n;
int a[N];

struct ST {
    int n;
    P st[LOGN][N];
    int mm[N];

    void init(){
        mm[0]=-1;
        for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i].first = a[i] + i;
            st[0][i].second = i;
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = max(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    P rmq(int l, int r){
        if(l >= n || r >= n) return {-1, n};
        int k = mm[r - l + 1];
        return max(st[k][l], st[k][r-(1<<k)+1]);
    }
}st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], a[i + n] = a[i];
    reverse(a, a + 2 * n);


    st.n = 2 * n;
    st.init();
    for(int i = 0; i < 2 * n; i++) {
        jp[0][i] = st.rmq(i + 1, i + a[i]).second;
    }
//    for(int i = 0; i < 2 * n; i++) {
//        cout << i + 1 << ": " << a[i] << ", " << jp[0][i] + 1 << endl;
//    }
    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j < 2 * n; j++) {
            int nxt = jp[i-1][j];
            jp[i][j] = nxt == 2 * n ? 2 * n : jp[i-1][nxt];
        }
    }


    ll res = 0;
    for(int i = 0; i < n; i++) {
        int cur = i;
        ll c_res = 0;
        if(a[i] + i >= i + n - 1) {
            c_res ++;
            res++;
        } else {
            for(int j = LOGN - 1; j >= 0; j--) {
                int nxt = jp[j][cur];
                if(nxt + a[nxt] < i + n - 1) {
                    c_res += (1 << j);
                    res += (1 << j);
                    cur = jp[j][cur];
                }
            }
            c_res += 2;
            res += 2;
        }
//        cout << i +  1<< ": " << c_res<< endl;

    }
    cout << res << endl;
}