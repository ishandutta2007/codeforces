#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
const int o=5e4+10,O=6e6;
#define ll long long
int n,m,typ[o],ans[o],t,fa[O],h[O],cnt;ll a[o],b[o];bool blk[O];char s[9];pair<ll,ll> itv[O];vector<pair<ll,ll> > g;
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
inline void merge(int x,int y){if((x=fr(x))^(y=fr(y))) fa[x]=y;}
struct Edge{int v,p;}e[O*16];
inline void ad(int U,int V){
	if(!blk[U]&&!blk[V]){merge(U,V);return;}
	e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;e[++cnt].v=U;e[cnt].p=h[V];h[V]=cnt;
}
int build(ll l,ll r,vector<pair<ll,ll> >&vec){
	if(vec.empty()){itv[t]=make_pair(l,r);blk[t++]=false;return 1;}
	if(vec.size()==1&&vec[0]==make_pair(l,r)){itv[t]=vec[0];blk[t++]=true;return 1;}
	long long md=l+r>>1;vector<pair<ll,ll> > vl,vr;
	for(int i=0,sz=vec.size();i<sz;++i)
		if(vec[i].second<=md) vl.push_back(vec[i]);
		else if(vec[i].first>md) vr.push_back(vec[i]);
		else vl.push_back(make_pair(vec[i].first,md)),vr.push_back(make_pair(md+1,vec[i].second));
	int bg=t,l1=build(l,md,vl);int l2=build(md+1,r,vr);
	for(int i=0,j=0;i<l1&&j<l2;){
		if(itv[i+bg].second+md-l+1>=itv[j+bg+l1].first&&itv[j+bg+l1].second>=itv[i+bg].first+md-l+1) ad(i+bg,j+bg+l1);
		if(itv[i+bg].second+md-l+1<itv[j+bg+l1].second) ++i;
		else ++j;
	}
	return l1+l2;
}
inline int fnd(long long x){
	int l=0,r=t-1,md;
	for(;l<r;) if(itv[md=(l+r>>1)+1].first<=x) l=md;else r=md-1;
	return l;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) scanf("%s%lld%lld",s,&a[i],&b[i]),typ[i]=(s[0]=='b');
	for(int i=1;i<=m;++i) if(typ[i]) g.push_back(make_pair(a[i],b[i]));
	for(int i=0;i<O;++i) fa[i]=i;
	sort(g.begin(),g.end());build(0,(1ll<<n)-1,g);
	for(int i=m,l,r,md;i;--i)
		if(typ[i]){
			for(l=0,r=t-1;l<r;) if(itv[md=(l+r>>1)+1].first<=a[i]) l=md;else r=md-1;
			for(int j;l<t&&itv[l].second<=b[i];++l) for(blk[l]=0,j=h[l];j;j=e[j].p) if(!blk[e[j].v]) merge(l,e[j].v);
		}
		else ans[i]=(fr(fnd(a[i]))==fr(fnd(b[i])));
	for(int i=1;i<=m;++i) if(!typ[i]) printf("%d\n",ans[i]);
	return 0;
}