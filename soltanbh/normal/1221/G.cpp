#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
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
const int N=41;

int n,m,x,y,k,b[N],matris[N][N],check[(1<<20)],n1,mj[22][(1<<20)],mark[N],dis[N];
vector<int> g[N];
ll ans=0,cmp1,cmp2,p,dp[(1<<20)];

void solve1(int mask){
	ll av=-1,p=0;
	f(i,0,n1){
		if(mask%(1<<(i+1))>=(1<<i)){
			if(av==-1)
				av=i+1;
			else if(matris[i+1][av]==0)
				p+=(1<<i);
		}
	}
	dp[mask]=dp[mask-(1<<(av-1))]+dp[p];
}
void chk(int mask){
	int c=0,mn=44;
	f(i,0,n-n1){
		if(mask%(1<<(i+1))>=(1<<i)){
			b[c]=n1+i+1;
			c++;
			minm(mn,check[mask-(1<<i)]);
		}
	}
	if(c!=2 && mn==1) check[mask]=1;
	if(c==2 && matris[b[0]][b[1]]==0) check[mask]=1;
}

ll mojaver(int x,int mask){
	if(mj[x][mask]>=0) return mj[x][mask];
	if(mask==0){mj[x][mask]=1;return 1;}
	f(i,0,n-n1){
		if(mask%(1<<(i+1))>=(1<<i)){
			mj[x][mask]=(matris[x][n1+i+1]==0 && mojaver(x,mask-(1<<i)));
			return mj[x][mask];
		}
	}
}
void solve2(ll mask){
	ll p=0;
	f(i,1,n1+1)
		if(mojaver(i,mask))
			p+=(1<<(i-1));
	ans=ans-dp[p]-dp[p];
}
void check_biparti_graph(ll x,ll dist,ll par){
	mark[x]=1;
	dis[x]=dist;
	f(i,0,g[x].size()){
		if(mark[g[x][i]] && g[x][i]!=par && dis[g[x][i]]%2==dis[x]%2)
			k=0;
	}
	f(i,0,g[x].size())
		if(mark[g[x][i]]==0)
			check_biparti_graph(g[x][i],dist+1,x);
}

int main(){
	dp[0]=check[0]=1;
	Gett(n,m);
	if(m<=1) return cout<<0,0;
	f(i,0,m){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
		matris[x][y]=1;
		matris[y][x]=1;
	}
	
	n1=n/2;
	f(i,0,22) f(j,0,(1<<20)) mj[i][j]=-1;
	f(i,1,(1<<n1)) solve1(i);
	f(i,1,(1<<n-n1)) chk(i);
	ans=(1ll<<1ll*n);
	f(i,0,(1<<n-n1)){
		if(check[i])
			solve2(i);
	}
	
	p=cmp1=cmp2=1;
	f(i,1,n+1){
		if(!mark[i]){
			k=1;
			check_biparti_graph(i,0,0);
			if(g[i].size()) cmp1*=2;
			else cmp2*=2;
			if(k)
				p=p*2;
			else
				p=0;
		}
	}
	
	ans=ans+p-(cmp1-2)*cmp2;
	cout<<ans<<endl;
}