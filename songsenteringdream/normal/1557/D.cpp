#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
inline pair<int,int> Max(pair<int,int> a,pair<int,int> b){return a>b?a:b;}
const int o=3e5+10,O=1e9;
int n,m,cnt,lst[o],ar[o*2];vector<int> ll[o],rr[o];bool vis[o];pair<int,int> zer=make_pair(0,0),rcd;map<int,int> hsh;
struct segmenttree{int l,r,ls,rs;pair<int,int> mx,lzy;}nod[o*20];
inline void build(int&id,int l,int r){if(!id) nod[id=++cnt].l=l,nod[id].r=r,nod[id].ls=nod[id].rs,nod[id].mx=nod[id].lzy=zer;}
void modify(int id,int l,int r,pair<int,int> val){
	nod[id].mx=Max(nod[id].mx,val);
	if(nod[id].l==l&&nod[id].r==r){nod[id].lzy=Max(nod[id].lzy,val);return;}
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) build(nod[id].ls,nod[id].l,md),modify(nod[id].ls,l,r,val);
	else if(md<l) build(nod[id].rs,md+1,nod[id].r),modify(nod[id].rs,l,r,val);
	else build(nod[id].ls,nod[id].l,md),build(nod[id].rs,md+1,nod[id].r),
		modify(nod[id].ls,l,md,val),modify(nod[id].rs,md+1,r,val);
}
pair<int,int> query(int id,int l,int r){
	if(!id) return zer;
	if(nod[id].l==l&&nod[id].r==r) return nod[id].mx;
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) return Max(query(nod[id].ls,l,r),nod[id].lzy);
	if(md<l) return Max(query(nod[id].rs,l,r),nod[id].lzy);
	return Max(nod[id].lzy,Max(query(nod[id].ls,l,md),query(nod[id].rs,md+1,r)));
}
int main(){
	read(n);read(m);
	for(int i,j,k;m--;) read(i),read(j),read(k),ll[i].push_back(ar[++cnt]=j),rr[i].push_back(ar[++cnt]=k);
	sort(ar+1,ar+1+cnt);for(int i=1;i<=cnt;++i) if(ar[i]^ar[i-1]) hsh[ar[i]]=++lst[0];
	for(int i=1;i<=n;++i) for(int j=0,k=ll[i].size();j<k;++j) ll[i][j]=hsh[ll[i][j]],rr[i][j]=hsh[rr[i][j]];
	build(m,1,lst[m=cnt=0]);
	for(int i=1;i<=n;++i){
		rcd=zer;
		for(int k=0,sz=ll[i].size();k<sz;++k) rcd=Max(rcd,query(1,ll[i][k],rr[i][k]));
		lst[i]=rcd.second;++rcd.first;rcd.second=i;
		for(int k=0,sz=ll[i].size();k<sz;++k) modify(1,ll[i][k],rr[i][k],rcd);
	}
	write(n-(rcd=nod[1].mx).first);putchar('\n');
	for(int i=rcd.second;i;i=lst[i]) vis[i]=1;
	for(int i=1;i<=n;++i) if(!vis[i]) write(i),putchar(' ');
	return 0;
}