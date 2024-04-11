#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define MP make_pair
#define F first
#define S second
using namespace std;
ll dp[30][30],tmp[26];
int main()
{
	ll n,o,O;cin>>n;
	for(ll k=0;k<n;k++)
	{
		char s[20];scanf("%s",s);ll num=0;
		while(s[num]!='\0') num++;

//		string s;cin>>s;ll num=s.size();
		
		pll p=MP(ll(s[0])-'a',ll(s[num-1])-'a');
		for(ll i=0;i<26;i++) tmp[i]=0;
		for(ll i=0;i<26;i++) {tmp[i]=dp[i][p.S];if(dp[i][p.F]>0||i==p.F) tmp[i]=max(tmp[i],dp[i][p.F]+num);}
		for(ll i=0;i<26;i++) dp[i][p.S]=tmp[i];
	}
	ll Max=0;
	for(ll i=0;i<26;i++) Max=max(Max,dp[i][i]);
	cout<<Max;
}