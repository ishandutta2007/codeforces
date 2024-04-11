#include<iostream>

using namespace std;

const long long N = 2007;
const long long mod = 1000000007;

long long a[N];
pair<long long, bool> dp[N][N];
long long fact_dp[N];

long long solve(long long n, long long k)
{
    if(k == 0)
        return fact_dp[n];
    if(k == 1)
        return (fact_dp[n] * n) % mod;
    
    if(dp[n][k].second)
        return dp[n][k].first;  
        
    dp[n][k].second = true;
    
    long long &res = dp[n][k].first;
    
    res += (solve(n, k-1) * n) % mod;
    res += (solve(n+1, k-2) * (k-1) ) % mod;
    res %= mod;
    
    return res;
}

long long mp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    
    cin >> n;
    
    for(long long i = 1; i <= n; i++)
        cin >> a[i];
        
    fact_dp[0] = 1;
    for(long long i = 1; i <= n; i++)
        fact_dp[i] = (fact_dp[i-1] * i) % mod;
        
    k = 0;
    
    for(long long i = 1; i <= n; i++)
    {
        if(a[i] == -1)
            mp[i]++;
        else
            mp[a[i]]--;
    }
    
    for(long long i = 1; i <= n; i++)
        if(mp[i] == 1)
        {
            k++;
            //cout << mp[i] << endl;
        }
    
    long long n2 = n;
    
    for(long long i = 1; i <= n; i++)
        if(a[i] != -1)
        {
            n2 --;
            //k --;
        }
    
    //cout << k << "\n";        
    cout << solve(n2-k, k) << "\n";
    
    
    
    //system("pause");
    
    return 0;
}