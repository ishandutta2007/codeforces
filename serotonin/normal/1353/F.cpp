#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105;

int n, m;
ll a[sz][sz], dp[sz][sz];
bool vis[sz][sz];

ll go(int x, int y, ll b)
{
    if(x >= n || y >= m) return -1;
    if(b > a[x][y]) return -1;
    if(!vis[x][y]) {
        vis[x][y] = 1;

        ll now = a[x][y] - b;
        if(x == n-1 && y == m-1) return dp[x][y] = now;

        ll one = go(x+1, y, b+1);
        ll two = go(x, y+1, b+1);

        ll mn;
        if(one < 0) mn = two;
        else if(two < 0) mn = one;
        else mn = min(one, two);

        if(mn >= 0) dp[x][y] = mn + now;
    }
    return dp[x][y];
}

ll fnc(ll b)
{
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = -1, vis[i][j] = 0;
        }
    }
    return go(0, 0, b);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%lld", &a[i][j]);
            }
        }

        ll ans = 1e18;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ll now = fnc(a[i][j] - i - j);
                if(now < 0) continue;
                ans = min(ans, now);
            }
        }

        printf("%lld\n", ans);
    }
}