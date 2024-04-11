#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
 
const int N=102,mod=1e9+7;

int n,x,y,sub[N],ans[N],C[N][N],dp[N][N][N];// ver,tcmp,lastcmp
vector<int> g[N];

ll pow(ll x,ll y,ll mod){
	ll res=1;
	f(i,0,y)
		res=res*x%mod;
	return res;
}
void dfs(int x,int par){
	sub[x]=1;
	dp[x][0][1]=1;
	f(io,0,g[x].size()){
		int u=g[x][io];
		if(u!=par){
			dfs(u,x);
			int newsz=sub[x]+sub[u];
			f_(i,newsz,0){
				f_(j,newsz,1){
					dp[x][i][j]=0;
					f(k,max(i-sub[u],0),min(i,sub[x])+1){
						f(l,max(j-sub[u],0),min(j,sub[x])+1){
							dp[x][i][j]=(dp[x][i][j]+1ll*dp[x][k][l]*dp[u][i-k][j-l]%mod)%mod;
						}
					}
				}
			}
			sub[x]=newsz;
		}
	}
	f(i,1,N)
			f(j,1,N)
				dp[x][i][0]=(dp[x][i][0]+1ll*dp[x][i-1][j]*j%mod)%mod;
}
void makeC(){
	C[0][0]=1;
	f(i,1,N){
		C[0][i]=1;
		f(j,1,i+1)
			C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
	}
}

int main(){
	makeC();
	cin>>n;
	f(i,1,n){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	ans[n-1]=1;
	ans[0]=1;
	f_(i,n-2,0){
		ans[i]=dp[1][n-i][0]*pow(n,n-i-2,mod)%mod;
		f(j,i+1,n)
			ans[i]=(ans[i]+mod-1ll*ans[j]*C[i][j]%mod)%mod;
	}
	f(i,0,n)
		cout<<ans[i]<<" ";
}