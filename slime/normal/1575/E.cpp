#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
Edgc
int a[SZ],n,k;
int vis[SZ],C=1,sz[SZ],root=0,rs,sum;
int fv[SZ],sw[SZ],fe[SZ]; ll sv[SZ];
vector<int> ns;
inline void gr(int x,int f=0)
{
	ns.pb(x);
	sz[x]=1; int ms=0;
    for esb(x,e,b)
    {
        if(b==f||vis[b]==C) continue;
        fe[b]=vc[e]; sv[b]=sv[x]+a[b];
        if(fv[x]==-1) fv[b]=b,sw[b]=0;
        else fv[b]=fv[x],sw[b]=sw[x]+(vc[e]!=fe[x]);
        gr(b,x); sz[x]+=sz[b];
        if(sz[b]>ms) ms=sz[b];
    }
    ms=max(ms,sum-sz[x]);
    if(ms<rs) root=x,rs=ms;
}
const int MOD=1e9+7;
int vfa[SZ],vsz[SZ];
ll ans=0,aans=0;
inline int dfz(int s,int bk,int df)
{
    sum=s;root=0;rs=1e9;
	ns.clear(); gr(bk);
	for(auto t:ns) fv[t]=-1,sw[t]=0,sv[t]=0;
	int x=root;
	ns.clear();
//	cout<<"EASY "<<s<<","<<bk<<","<<df<<","<<x<<"\n";
	gr(x);
	for(auto t:ns) if(sw[t]<=k)
//		cout<<x<<"->"<<t<<":"<<sw[t]<<" "<<sv[t]+a[x]<<"\n",
		ans+=sv[t]+a[x],ans%=MOD;
	{
	vector<pair<int,pii>> vs[2],vg[2];
	map<int,vector<int>> laji;
	for(auto t:ns) if(sw[t]<=k&&fv[t]!=-1)
		laji[fv[t]].pb(t),laji[0].pb(t);
	for(auto&tt:laji) {
		int cv=(tt.fi==0)?1:(-1);
		for(int o=0;o<2;++o) vs[o].clear(),vg[o].clear();
		for(auto t:tt.se)
			vs[fe[fv[t]]].pb(mp(sw[t],pii(1,sv[t]%MOD)));
		for(int o=0;o<2;++o) {
			vg[o]=vs[o];
			vg[o].pb(mp(-1e9,pii(0,0)));
			sort(vg[o].begin(),vg[o].end());
			int ss=0,s0=0;
			for(auto&x:vg[o])
				(s0+=x.se.fi),
				x.se.fi=s0,
				(ss+=x.se.se)%=MOD,
				x.se.se=ss;
		}
		for(int o=0;o<2;++o)
			for(auto t:vs[o]) {
				for(int p=0;p<2;++p) {
					auto id=(lower_bound(vg[p].begin(),vg[p].end(),
					mp(k-t.fi-(o!=p)+1,pii(-1e9,0)))-1)->se;
					aans+=cv*(id.se+id.fi%MOD*ll(t.se.se+a[x])%MOD);
					aans%=MOD;
				}
			}
	}
	}
	vfa[x]=df; vsz[x]=s; vis[x]=C;
    for esb(x,e,g)
        if(vis[g]!=C) dfz(sz[g],g,x);
    return x;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1,u,v,w;i<n;++i)
		scanf("%d%d%d",&u,&v,&w),
		adde(u,v,w);
	dfz(n,1,0);
	aans%=MOD;
	ans+=aans*((MOD+1)/2)%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}