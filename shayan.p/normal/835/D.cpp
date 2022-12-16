#include<bits/stdc++.h>
#define ll int
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
const ll maxn=6000;
ll dp[maxn][maxn],ans[maxn];
int main()
{
	string s;cin>>s;ll sz=s.size();
	for(ll i=sz-1;i>=0;i--)
		for(ll j=i;j<sz;j++)
		if(s[i]==s[j])
		{
			if(i==j) dp[i][j]=1;
			else if(i+1==j) dp[i][j]=2;
			else if(dp[i+1][j-1]) {ll l=((j-i)+1)/2;dp[i][j]=min(dp[i][i+l-1],dp[j-l+1][j])+1;}
			ans[dp[i][j]]++;
		}
		stack<ll> S;ll sum=0;
		for(ll i=sz;i>0;i--) {sum+=ans[i];S.push(sum);}
		for(ll i=0;i<sz;i++) {cout<<S.top()<<" ";S.pop();}
}