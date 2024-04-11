#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1000 + 10;
const int MAXM = 200000 + 10;
int n, m, a[MAXN];
ll b[MAXM], s[MAXN], dp[MAXN];
int main()
{
    int i, j, res = 0;
    ll sum = 0;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    for(i = 1; i <= m; i++)
    {
        scanf("%I64d", &b[i]);
    }
    for(i = 1; i <= n; i++)
    {
        sum = 0, dp[i] = 0;
        for(j = i; j <= n; j++)
        {
            if(a[i] <= a[j])
            {
                sum += a[j];
                dp[i] = min(dp[i], sum);
            }
        }
    }
    for(i = 1; i <= m; i++)
    {
        ll t = b[i];
        res = 0;
        for(j = 1; j <= n; j++)
        {
            if(t+dp[j]<0) res++;
            else t += a[j];
        }
        cout << res << endl;
    }
}