#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, INF = (int)1e9;

int n, m;
int a[N], b[N];
int p[N], dp[N];
int fir[N], las[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
        sort(b, b + n);
        m = (int)(unique(b, b + n) - b);
        for(int i = 0; i < m; i++) p[b[i]] = i;
        fill(fir, fir + n, INF);
        fill(las, las + n, -1);
        for(int i = 0; i < n; i++) {
            a[i] = p[a[i]];
            fir[a[i]] = min(fir[a[i]], i);
            las[a[i]] = max(las[a[i]], i);
        }
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < m; i++) {
            dp[i] = 1;
            if(fir[i] > las[i-1]) dp[i] = max(dp[i], dp[i-1] + 1);
            res = max(res, dp[i]);
        }
        cout << m - res << '\n';



    }

}