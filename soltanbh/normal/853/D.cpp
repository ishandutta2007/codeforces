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

const int N=5e5+99,M=45,inf=1e9;

int n,t,a[N],dp[N][M],ans=inf;

int main(){
	cin>>n;
	f(i,1,n+1){ cin>>a[i];	a[i]/=1000; }
	f(i,1,M) dp[0][i]=inf;
	f(i,1,n+1)
		f(j,0,M){
			dp[i][j]=inf;
			if(j>=a[i])
				dp[i][j]=dp[i-1][j-a[i]]+a[i]*10;
			f(l,j+1,M)
				minm(dp[i][j],dp[i-1][l]+max(a[i]*10-(l-j),0));
		}
	f(i,0,M) minm(ans,dp[n][i]);
	cout<<ans*100ll;
}