#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline long long Min(long long a,long long b){return a<b?a:b;}
inline long long Max(long long a,long long b){return a>b?a:b;}
const int o=2e5+10;
int n,q,a[o];
struct segmenttree{int l,r,al,ar;long long s;}nod[o*3];
inline void update(int id,int md){
	nod[id].al=nod[id<<1].al,nod[id].ar=nod[(id<<1)|1].ar;
	nod[id].s=nod[id<<1].s+nod[(id<<1)|1].s;
	if(a[md]<=a[md+1]){
		if(nod[id].al==md) nod[id].al=nod[(id<<1)|1].al;
		if(nod[id].ar==md+1) nod[id].ar=nod[id<<1].ar;
		nod[id].s+=(md-nod[id<<1].ar+1)*1ll*(nod[(id<<1)|1].al-md); 
	}
}
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;
	if(l==r){nod[id].al=nod[id].ar=l;nod[id].s=1;return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	update(id,md);
}
void modify(int id,int pos){
	if(nod[id].l==nod[id].r) return;
	int md=nod[id].l+nod[id].r>>1;
	if(pos<=md) modify(id<<1,pos);
	else modify((id<<1)|1,pos);
	update(id,md); 
}
long long query(int id,int l,int r){
	if(nod[id].l==l&&nod[id].r==r) return nod[id].s;
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) return query(id<<1,l,r);
	if(md<l) return query((id<<1)|1,l,r);
	return query(id<<1,l,md)+query((id<<1)|1,md+1,r)+
	(a[md]<=a[md+1])*(md-Max(l,nod[id<<1].ar)+1)*1ll*(Min(r,nod[(id<<1)|1].al)-md);
}
int main(){
	read(n);read(q);
	for(int i=1;i<=n;++i) read(a[i]);
	build(1,1,n);
	for(int opt,x,y;q--;){
		read(opt);read(x);read(y);
		if(opt==1) a[x]=y,modify(1,x);
		else printf("%lld\n",query(1,x,y));
	}
	return 0;
}