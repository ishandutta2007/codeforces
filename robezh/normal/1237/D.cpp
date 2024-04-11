#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 500, LOGN = 18, INF = (int)1e9 + 50;


int n;
int a[N];
int dp[N];

int st[LOGN + 1][N], mm[N];


void init() {
    mm[0]=-1;
    for(int i = 1; i < 2 * n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
    for(int i = 0; i < 2 * n; i++){
        st[0][i] = a[i];
    }
    for(int lg = 1; lg < LOGN; lg++){
        for(int j = 0; j + (1 << lg) - 1 < 2 * n; j++){
            st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
        }
    }
}

int rmq(int l, int r){
    int k = mm[r - l + 1];
    return min(st[k][l], st[k][r-(1<<k)+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n; i < 2 * n; i++) a[i] = a[i - n];
    init();
    int mx = a[n-1];
    dp[n-1] = INF;
    for(int i = n; i < 4 * n - 1; i++) {
        if(2 * a[i % n] < mx) {
            dp[n-1] = i;
            break;
        }
        mx = max(mx, a[i % n]);
    }
    if(dp[n-1] == INF) {
        for(int i = 0; i < n; i++) cout << "-1" << " ";
        return 0;
    }

    for(int i = n - 2; i >= 0; i--) {
        int l = i, r = i + n, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(2 * rmq(i, mid) < a[i]) r = mid;
            else l = mid;
        }
//        cout << i << ", r: " << r << endl;
        if(r != i + n) dp[i] = min(r, dp[i+1]);
        else dp[i] = dp[i+1];
    }
    for(int i = 0; i < n; i++) {
        cout << dp[i] - i << " ";
    }
}