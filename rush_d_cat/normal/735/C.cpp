#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int NICO = 92;
ll dp[NICO], sum[NICO];
int main()
{
    dp[1] = 1;sum[1] = 1;
    dp[2] = 1;sum[2] = 2;
    for(int i=3;i<NICO;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        sum[i] = sum[i-1] + dp[i];
    }
    ll n; cin >> n;
    for(int i=1;i<NICO;i++)
    {   
        if(sum[i] > n-1)
        {
            cout << i-1 << endl;
            return 0;
        }
    }
}