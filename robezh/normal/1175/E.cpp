#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)5e5 + 50, LOGN = 20, INF = (int)1e9;

int n, m;
int to[N];
int jp[LOGN][N];

struct ST {
    int n;
    P st[LOGN][N];
    int mm[N];

    void init(){
        mm[0]=-1;
        for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i].first = to[i];
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

    cin >> n >> m;
    for(int i = 0; i < N; i++) to[i] = i;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        to[l] = max(to[l], r);
    }
    int rmax = 0;
    for(int i = 0; i < N; i++) {
        to[i] = max(to[i], rmax);
        rmax = max(to[i], rmax);
    }
    st.n = N;
    st.init();
    for(int i = 0; i < N; i++) jp[0][i] = st.rmq(i, to[i]).second;
    for(int lg = 1; lg < LOGN; lg++) {
        for(int i = 0; i < N; i++) jp[lg][i] = jp[lg-1][jp[lg-1][i]];
    }
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        int res = 1;
        int cur = x;
        if(to[x] < y) {
            if(to[jp[LOGN-1][x]] < y) res = -1;
            else {
                for(int lg = LOGN - 1; lg >= 0; lg--) {
                    if(to[jp[lg][cur]] < y) {
                        cur = jp[lg][cur];
                        res += (1 << lg);
                    }
                }
                res++;
            }

        }
        cout << res << "\n";
    }


}