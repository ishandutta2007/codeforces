#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define MAXN 3002
int a[MAXN],b[MAXN];ll dp[MAXN][MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(a+1, a+1+n);
    ll res = 1e18;
    for(int i=1;i<=n;i++){
        dp[1][i] = abs(b[1] - a[i]);
    }
    for(int i=2;i<=n;i++){
        ll min_ = 1e18;
        for(int j=1;j<=n;j++){
            min_ = min(min_, dp[i-1][j]);
            dp[i][j] = min_ + abs(b[i] - a[j]);
            if((i==n)&&(dp[i][j]<=res)) res = dp[i][j];
        }
    }
    res = min(res, dp[n][1]);
    cout << res << endl;
}