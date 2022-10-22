#include<cstdio>
#include<set>
using namespace std;
const int o=1e6,E=2e5+20;
int n,q,c[o],a[o],flg[o],s[o],len[o];
void build(int id,int l,int r){
	flg[id]=2;len[id]=r-l+1;
	if(l==r){s[id]=c[l];return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	s[id]=s[id<<1]+s[(id<<1)|1];
}
inline void ad(int id,int val){flg[id]=val;s[id]=len[id]*val;}
inline void pushdown(int id){if(flg[id]<2) ad(id<<1,flg[id]),ad((id<<1)|1,flg[id]),flg[id]=2;}
void modify(int id,int ql,int qr,int val,int l=1,int r=E){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	s[id]=s[id<<1]+s[(id<<1)|1];
}
int query0(int id,int pos,int l=1,int r=E){
	if(!s[id]) return r;
	if(l==r) return l-1;
	pushdown(id);
	int md=l+r>>1,res;
	if(pos>md) return query0((id<<1)|1,pos,md+1,r);
	if((res=query0(id<<1,pos,l,md))==md) return query0((id<<1)|1,pos,md+1,r);
	return res;
}
int query1(int id,int pos,int l=1,int r=E){
	if(s[id]==len[id]) return r;
	if(l==r) return l-1;
	pushdown(id);
	int md=l+r>>1,res;
	if(pos>md) return query1((id<<1)|1,pos,md+1,r);
	if((res=query1(id<<1,pos,l,md))==md) return query1((id<<1)|1,pos,md+1,r);
	return res;
}
int query(int id,int l,int r){
	if(l==r) return l;
	pushdown(id);
	int md=l+r>>1;
	if(s[(id<<1)|1]) return query((id<<1)|1,md+1,r);
	return query(id<<1,l,md);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),++c[a[i]];
	for(int i=1;i<E;++i) c[i+1]+=c[i]/2,c[i]%=2;
	build(1,1,E);
	for(int k,l,r;q--;printf("%d\n",query(1,1,E))){
		scanf("%d%d",&k,&l);
		if((r=query0(1,a[k]))>=a[k]) modify(1,a[k],r,1);
		modify(1,r+1,r+1,0);
		if((r=query1(1,a[k]=l))>=l) modify(1,l,r,0);
		modify(1,r+1,r+1,1);
	}
	return 0;
}