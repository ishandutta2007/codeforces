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
#define bit(x) (1ll<<(x*1ll))
#define add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9,mod=1e9+7,sq=318;
int n,m,x,fac[N];
vector<vector<int> > dp[N];
vector<int> v;

int main(){
	cin>>n>>m>>x;
	if(n>m) return cout<<0,0;
	
	fac[0]=1;
	f(i,1,sq) fac[i]=1ll*fac[i-1]*i%mod;
	f(i,0,n+1) v.pb(0);
	f(i,0,m+1) f(j,0,n+1) dp[i].pb(v);
	dp[0][0][0]=1;
	
	f(i,1,m+1)
		f(j,0,min(i,n)+1)
			f(k,0,j+1){
				if(j>0) add(dp[i][j][k],dp[i-1][j-1][k]);
				if(j>0 && k>0) add(dp[i][j][k],dp[i-1][j-1][k-1]);
				if(i!=x){
					add(dp[i][j][k],dp[i-1][j][k]);
					if(k>0) add(dp[i][j][k],dp[i-1][j][k-1]);
				}
			}
	cout<<1ll*dp[m][n][n]*fac[n]%mod;
}