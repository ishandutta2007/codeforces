#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500, LOGN = 19;
typedef pair<int, int> P;
typedef long long ll;

int n;
int a[N],b[N];
ll res = 0;

struct ST {
    int mm[N];
    int mx[LOGN + 1][N], mn[LOGN + 1][N];

    void init(){
        mm[0]=-1;
        for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            mx[0][i] = a[i];
            mn[0][i] = b[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                mx[lg][j] = max(mx[lg-1][j], mx[lg-1][j+(1<<(lg-1))]);
                mn[lg][j] = min(mn[lg-1][j], mn[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    int rmq(int l, int r){
        int k = mm[r - l + 1];
        return max(mx[k][l], mx[k][r-(1<<k)+1]) - min(mn[k][l], mn[k][r-(1<<k)+1]);
    }
} st;

int get_lower(int i, int x) {
    int l = i - 1, r = n, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(st.rmq(i, mid) >= x) r = mid;
        else l = mid;
    }
    return r;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    st.init();
    for(int i = 0; i < n; i++) {
        res += get_lower(i, 1) - get_lower(i, 0);
    }
    cout << res << endl;
}