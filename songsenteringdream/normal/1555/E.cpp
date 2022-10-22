#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
const int o=1e6+10;
struct segmenttree{int l,r,mn,flg;}nod[o*4];
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;nod[id].mn=nod[id].flg=0;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void pushdown(int id){
	nod[id<<1].mn+=nod[id].flg;nod[(id<<1)|1].mn+=nod[id].flg;
	nod[id<<1].flg+=nod[id].flg;nod[(id<<1)|1].flg+=nod[id].flg;
	nod[id].flg=0;
}
void modify(int id,int l,int r,int val){
	if(nod[id].l==l&&nod[id].r==r){nod[id].mn+=val;nod[id].flg+=val;return;}
	pushdown(id);
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) modify(id<<1,l,r,val);
	else if(md<l) modify((id<<1)|1,l,r,val);
	else modify(id<<1,l,md,val),modify((id<<1)|1,md+1,r,val);
	nod[id].mn=Min(nod[id<<1].mn,nod[(id<<1)|1].mn);
}
int n,m,ans=1e7;
struct itv{int l,r,w;}t[o];
inline bool cmp(itv A,itv B){return A.w<B.w;}
int main(){
	read(n);read(m);
	build(1,1,--m);
	for(int i=1;i<=n;++i) read(t[i].l),read(t[i].r),--t[i].r,read(t[i].w);
	sort(t+1,t+1+n,cmp);
	for(int i=1,p=1;i<=n;++i){
		for(modify(1,t[i].l,t[i].r,1);nod[1].mn;++p) modify(1,t[p].l,t[p].r,-1);
		if(p>1) ans=Min(ans,t[i].w-t[p-1].w);
	}
	write(ans);
	return 0;
}