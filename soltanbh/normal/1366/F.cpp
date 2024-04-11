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
#define int ll

const int N=2005,inf=1e9+5,mod=1e9+7;

int n,m,q,w,u,v,p,sz,c[N],mxe[N],a[N*N];
pair<int,pair<int,int> > conv[N*N];
vector<pair<int,int> > g[N];
pair<int,int> dist[N][N];
ll ans,t,ad;

void do_it(){
	f(i,0,N) f(j,0,N) dist[i][j].F=-1;
	dist[1][0].F=0;
	f(i,1,m+1){
		f(j,1,n+1){
			f(k,0,g[j].size())
				if(dist[g[j][k].F][i-1].F!=-1 && dist[g[j][k].F][i-1].F+g[j][k].S>dist[j][i].F){
					dist[j][i].F=dist[g[j][k].F][i-1].F+g[j][k].S;
					dist[j][i].S=max(dist[g[j][k].F][i-1].S,g[j][k].S);
				}
		}
	}
}
int tagh(int a1,int b1,int a2,int b2){
    return max((b2-b1+a1-a2-1)/(a1-a2),1ll);
}
void convex_hull(){
	sort(a,a+p);
	f(i,1,N*N){
		if(a[i]!=-inf){
			u=i,v=a[i];
			while(sz>0 && tagh(u,v,conv[sz-1].S.F,conv[sz-1].S.S)<=conv[sz-1].F)
				sz--;
			if(sz==0) conv[sz]=(mp(1,mp(u,v))),sz++;
			else
				conv[sz]=mp(tagh(u,v,conv[sz-1].S.F,conv[sz-1].S.S),mp(u,v)),sz++;
		}
	}
}
ll e(ll x,ll y){
	return (y*(y+1ll)/2-x*(x+1ll)/2)%mod;
}

main(){
	f(i,0,N*N) a[i]=-inf;
	cin>>n>>m>>q;
	f(i,0,m){
		Gett(u,v);
		gett(w);
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
		maxm(mxe[u],w);
		maxm(mxe[v],w);
	}
	do_it();
	f(i,1,n+1)
		f(j,0,m+1){
			u=mxe[i],v=dist[i][j].F-u*j;
			if(v<=0 && dist[i][j].F!=-1 && dist[i][j].S<mxe[i])
				maxm(a[u],v);
		}
	convex_hull();
	conv[sz].F=1e9+2,sz++;
	f(i,1,sz){
		t=min(conv[i].F,q+1)-conv[i-1].F;
		ad=(t*conv[i-1].S.S+e(conv[i-1].F-1,min(conv[i].F,q+1)-1)*conv[i-1].S.F);
		if(ad<0) ad=(ad+mod*mod)%mod;
		ans=(ans+ad)%mod;
		if(conv[i].F>q) break;
	}
	cout<<ans;
}