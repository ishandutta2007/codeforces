#include<bits/stdc++.h>

using namespace std;

const long long mx = 4e5;
const long long inf = 1e18;

long long dp[mx];

int main ()
{
    long long a, b, k;
    
    cin >> a >> b >> k;
    
    long long lcm = 1ll;
    
    for(long long i = 2; i <= k; i++)
    {
        lcm = lcm*i/__gcd(lcm,i);         
    }
    
    long long diff = (a-b) / lcm;
    
    if(b % lcm > a % lcm)
        diff++;
        
    if(diff == 0)
    {
        for(int i = 0; i < b%lcm; i++)
            dp[i] = inf;

        dp[b % lcm] = 0;
        
        for(long long i = b%lcm+1; i <= a%lcm; i++)
        {
            dp[i] = dp[i-1] + 1;
            
            for(long long j = 2; j <= k; j++)
                dp[i] = min(dp[i], dp[i - i%j] + 1);
        }
        
        cout << dp[a % lcm] << "\n";
        
        return 0;
    }
    
    dp[0] = 0;
    
    for(long long i = 1; i < lcm; i++)
    {
        dp[i] = dp[i-1] + 1;
        
        for(long long j = 2; j <= k; j++)
            dp[i] = min(dp[i], dp[i - i%j] + 1);
    }

   // cout << lcm << " lcm\n";
    
    long long res = dp[a % lcm];

    //cout << res << " first\n";

    res += (diff-1)*dp[lcm-1];

    //cout << res << " second\n";

    for(int i = 0; i < b%lcm; i++)
            dp[i] = inf;

    dp[b % lcm] = 0;

    for(long long i = (b % lcm)+1; i < lcm; i++)
    {
        dp[i] = dp[i-1] + 1;

        for(long long j = 2; j <= k; j++)
            dp[i] = min(dp[i], dp[i - i%j] + 1);
    }

    res += dp[lcm-1];
    res += diff;

    cout << res << "\n";
    
    return 0;
}