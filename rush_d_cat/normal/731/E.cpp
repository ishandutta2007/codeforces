#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 200000 + 10;
typedef long long ll;
int n, i;
ll pre[MAXN], cnt[MAXN], a[MAXN], dp[MAXN];
int main()
{
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    dp[n] = pre[n];
    ll max_ = pre[n];
    for(i = n-1; i >= 2; i--)
    {
        max_ = max(max_, pre[i] - dp[i+1]);
        dp[i] = max_;
    }
    cout << dp[2] << endl;
}