#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int k,t,a,b;
int dp[N],sum[N];
 
signed main()
{
    cin>>t>>k;
    for(int i=0;i<k;i++) dp[i]=1;
    for(int i=k;i<N;i++) dp[i]=(dp[i-1]+dp[i-k])%mod;
    for(int i=1;i<N;i++) sum[i]=(sum[i-1]+dp[i])%mod;
    while(t--) 
	{
        cin>>a>>b;
        cout<<(sum[b]-sum[a-1]+mod)%mod<<endl;
    }
}