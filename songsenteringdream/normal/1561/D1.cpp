#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;}
const int o=2e5+10;
int n,m,f[o];
inline int fix(int x){return x+(x>>31&m);}
struct segmenttree{int l,r,lzy;}nod[o*3];
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;nod[id].lzy=0;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
void modify(int id,int l,int r,int val){
	if(nod[id].l==l&&nod[id].r==r){nod[id].lzy=fix(nod[id].lzy+val-m);return;}
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) modify(id<<1,l,r,val);
	else if(md<l) modify((id<<1)|1,l,r,val);
	else modify(id<<1,l,md,val),modify((id<<1)|1,md+1,r,val);
}
int query(int id,int pos){
	if(nod[id].l==nod[id].r) return nod[id].lzy;
	int md=nod[id].l+nod[id].r>>1;
	if(pos<=md) return fix(nod[id].lzy+query(id<<1,pos)-m);
	return fix(nod[id].lzy+query((id<<1)|1,pos)-m);
}
int main(){
	read(n);read(m);build(1,1,n);modify(1,1,1,1);
	for(int i=1;i<=n;++i){
		f[i]=fix(query(1,i)+f[i-1]-m);
		for(int j=2;i*j<=n;++j) modify(1,i*j,Min((i+1)*j-1,n),f[i]);
		f[i]=fix(f[i]+f[i-1]-m);
	}
	printf("%d",fix(f[n]-f[n-1]));
	return 0;
}