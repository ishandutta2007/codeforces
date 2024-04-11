#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1005;
ll n,t,k,ans[N],dp[N][N],sum,mod=1e9+7;
string s;
void Get_ans(int x){
	int c=x,h=0;
	while(c){
		h+=c%2;
		c/=2;
	}
	ans[x]=ans[h]+1;
}
int main(){
	cin>>s>>k;
	if(k==0) return cout<<1,0;
	ans[1]=0;
	f(i,2,1003)
		Get_ans(i);
	n=s.size();
	dp[n-1][0]=1;
	dp[0][0]=1;
	t=1;
	f(i,1,n){
		dp[i][0]=1;
		f(j,1,N)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
		if(s[i]=='1')
			dp[i][t]++,dp[i][t]%=mod;
		t+=(s[i]=='1');
	}
	dp[n-1][1]--;
	dp[n-1][t]++;
	f(i,1,N){
		if(ans[i]==k-1)
			sum=(sum+dp[n-1][i])%mod;
	}
	cout<<sum<<endl;
}