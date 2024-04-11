#include<cstdio>
#include<utility>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline pair<int,int> Min(pair<int,int> a,pair<int,int> b){return a<b?a:b;}
inline pair<int,int> Max(pair<int,int> a,pair<int,int> b){return a>b?a:b;}
const int o=2e6+10,inf=1e9;
int n,a[o],b[o],lst[o];bool vis[o];
	namespace SGT{
#define md (l+r>>1)
pair<int,int> mn[o],mx[o],flg[o];int pos[o];
void build(int id,int l,int r){
	mn[id]=mx[id]=flg[id]=make_pair(inf,0);pos[id]=l;
	if(l==r) return;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void cov(int id,pair<int,int> val)
{if(mn[id].first+1) mn[id]=Min(mn[id],val),mx[id]=Min(mx[id],val),flg[id]=Min(flg[id],val);}
inline void pushdown(int id){cov(id<<1,flg[id]);cov((id<<1)|1,flg[id]);flg[id]=make_pair(inf,0);}
inline void update(int id){
	if(mn[id<<1].first<0) mn[id]=mn[(id<<1)|1],pos[id]=pos[(id<<1)|1];
	else if(mn[(id<<1)|1].first<0) mn[id]=mn[id<<1],pos[id]=pos[id<<1];
	else mn[id]=Min(mn[id<<1],mn[(id<<1)|1]),pos[id]=(mn[id]==mn[id<<1]?pos[id<<1]:pos[(id<<1)|1]);
	mx[id]=Max(mx[id<<1],mx[(id<<1)|1]);
}
void modify(int id,int ql,int qr,pair<int,int> val,int l=0,int r=n){
	if(ql>qr||val>=mx[id]) return;
	if(ql<=l&&r<=qr){cov(id,val);return;}
	if(flg[id].first^inf) pushdown(id);
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	update(id);
}
void qd(int id,int pos,pair<int,int> val,bool typ,int l=0,int r=n){
	if(l==r){mn[id]=(typ?Min(mn[id],val):val);mx[id]=mn[id];return;}
	if(flg[id].first^inf) pushdown(id);
	if(pos<=md) qd(id<<1,pos,val,typ,l,md);
	else qd((id<<1)|1,pos,val,typ,md+1,r);
	update(id);
}
	}
void prt(int x){if(lst[x]<n) prt(lst[x]);printf("%d ",x);}
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) read(b[i]);
	SGT::build(1,0,n);SGT::qd(1,n,make_pair(0,0),0);
	for(int u,vv,ds;1;){
		u=SGT::pos[1];ds=SGT::mn[1].first;if(!lst[u]) lst[u]=SGT::mn[1].second;
		if(!u&&ds<inf){printf("%d\n",ds);prt(0);return 0;}
		if(ds>=inf||ds==-1) break;
		SGT::qd(1,u,make_pair(-1,0),0);
		if(vis[u]) continue;vis[u]=1;
		vv=u+b[u];
		SGT::modify(1,vv-a[vv],vv,make_pair(ds+1,u));
	}
	printf("-1");
	return 0;
}