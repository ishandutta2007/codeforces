#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int NICO = 1000 + 10;
ll num;char s[NICO];
ll dp[NICO][NICO];
ll ans[NICO];int cnt[NICO];
void init()
{
    for(int i=0;i<NICO;i++)
    {
        ans[i] = 1e18;
    }
}

ll pow(ll x, int y)
{
    ll res = 1;
    while(y--) 
    {
        if(res/10000.0*x/10000.0>1e10) return 0;
        res *= x;
    }
    return res;
}

int f(int x)
{
    int res = 0;
    while(x)
    {
        res ++;
        x /= 10;
    }
    return res;
}
int main()
{
    init();
    cin >> num;
    scanf("%s", s+1);
    int n = strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j+i<=n;j++)
        {
            if(j==0) dp[i][i+j] = s[i] - '0';
            else dp[i][i+j] = 10 * dp[i][i+j-1] + s[i+j] - '0'; 
        }
    }
    int len = f(num);
    ans[n+1] = 0; cnt[n+1] = -1;
    ans[n] = s[n]-'0'; cnt[n] = 0;
    for(int i=n-1;i>=1;i--)
    {
        ll tmp = 1e18;
        if(s[i] == '0')
        {
            cnt[i] = cnt[i+1]+1;
            ans[i] = ans[i+1];
            continue;
        }
        for(int j=i+1;j<=min(i+len, n+1);j++)
        {
            if(dp[i][j-1] >= num) continue;
            if(dp[i][j-1]/100000.0 * pow(num, cnt[j]+1)/100000.0 > 1e8) continue;
            if(ans[j] > 1e18 || pow(num, cnt[j]+1) == 0) continue;
           // cout << ans[j] << " " << dp[i][j-1]<<" "<<pow(num,cnt[j]+1) << endl;
            if(tmp > dp[i][j-1]*pow(num, cnt[j]+1) + ans[j]) 
            {
                cnt[i] = cnt[j] + 1;
                tmp = dp[i][j-1]*pow(num, cnt[i]) + ans[j];
            }
        }
        //cout << i << " -> " << tmp << " " << cnt[i] << endl;
        ans[i] = tmp;
    }
    cout << ans[1] << endl;
}