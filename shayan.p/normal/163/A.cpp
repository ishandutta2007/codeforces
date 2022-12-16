#include<bits/stdc++.h>
#define ll long
using namespace std;
const ll maxn=5010,mod=1e9+7;
ll dp,sum[maxn][maxn],ans;//sum[i][j]: dp[i][j]+dp[i][j-1]+dp[i][j-2]+...
int main(){
	string s,t;cin>>s>>t;
	dp=(s[0]==t[0]);
	sum[0][0]=dp;
	ans+=dp;
	for(ll i=1;i<t.size();i++){
		dp=(s[0]==t[i]);
		sum[0][i]=sum[0][i-1]+dp;
		ans+=dp;
	}
	for(ll i=1;i<s.size();i++){
		dp=(s[i]==t[0]);
		sum[i][0]=dp;
		ans+=dp;
	}
	for(ll i=1;i<s.size();i++){
		for(ll j=1;j<t.size();j++){
			dp=0;
			if(s[i]==t[j]){
				dp=1+sum[i-1][j-1];
				ans=(ans+dp)%mod;
			}
			sum[i][j]=(sum[i][j-1]+dp)%mod;
		}

	}
	cout<<ans;
}