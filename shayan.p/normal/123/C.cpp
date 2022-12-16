//														In the Name of Allah
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define F first
#define S second
using namespace std;
const ll inf=1e18+1,maxn=210;
pll p[maxn];
ll n,m,k;
ll dp[maxn][maxn];
char s[maxn];
void change_to_1D(){
	fill(p,p+maxn,MP(inf,inf));
	cin>>n>>m>>k;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			ll x;cin>>x;
			p[i+j]=MP(min(x,p[i+j].F),i+j);
		}
	}
	sort(p,p+n+m-1);
}
ll calc(){
	memset(dp,0,sizeof dp);
	dp[0][1]=1;
	if(s[0]==')')return 0;
	for(ll i=1;i<m+n-1;i++){
		for(ll j=0;j<=m+n-1;j++){
			if(s[i]==')'){
				if(j==m+n-1)dp[i][j]=0;
				else dp[i][j]=dp[i-1][j+1];
			}
			else if(s[i]=='('){
				if(j==0)dp[i][j]=0;
				else dp[i][j]=dp[i-1][j-1];
			}
			else{
				if(j==0)dp[i][j]=dp[i-1][j+1];
				else if(j==m+n-1)dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			}
			if(dp[i][j]>inf)dp[i][j]=inf;
		}
	}
	return dp[m+n-2][0];
}
void print(){
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cout<<s[i+j];
		}
		cout<<endl;
	}
}
int main(){
	change_to_1D();
	ll now=0;
	for(ll i=0;i<n+m-1;i++){
		s[p[i].S]='(';
		ll a=calc();
		if(a+now>=k){//should be (
			s[p[i].S]='(';
		}
		else{// should be )
			now+=a;
			s[p[i].S]=')';
		}
	}
	print();
}