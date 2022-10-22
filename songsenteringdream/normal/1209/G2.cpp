#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int o=1e6;
int n,q,a[o],mn[o],mx[o],flg[o],lv[o],rv[o],mv[o];set<int> s[o];
inline void ad(int id,int val){mn[id]+=val;flg[id]+=val;}
inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
inline void update(int id){
	mx[id]=max(mx[id<<1],mx[(id<<1)|1]);mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
	if(mn[id<<1]<mn[(id<<1)|1]) mv[id]=mv[id<<1],lv[id]=lv[id<<1],rv[id]=max(mx[(id<<1)|1],rv[id<<1]);
	else if(mn[id<<1]>mn[(id<<1)|1]) mv[id]=mv[(id<<1)|1],rv[id]=rv[(id<<1)|1],lv[id]=max(mx[id<<1],lv[(id<<1)|1]);
	else lv[id]=lv[id<<1],rv[id]=rv[(id<<1)|1],mv[id]=mv[id<<1]+mv[(id<<1)|1]+max(rv[id<<1],lv[(id<<1)|1]);
}
void modify(int id,int ql,int qr,int val,int l=1,int r=n){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	update(id);
}
void assign(int id,int pos,int val,int l=1,int r=n){
	if(l==r){mx[id]=lv[id]=val;return;}
	pushdown(id);
	int md=l+r>>1;
	if(pos<=md) assign(id<<1,pos,val,l,md);
	else assign((id<<1)|1,pos,val,md+1,r);
	update(id);
}
void ins(int c,int coef){
	if(s[c].empty()) return;
	assign(1,*s[c].begin(),(coef>0)*s[c].size());
	if((*s[c].begin())<(*s[c].rbegin())) modify(1,*s[c].begin(),(*s[c].rbegin())-1,coef);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[a[i]].insert(i);
	for(int i=1;i<o;++i) ins(i,1);
	printf("%d\n",n-mv[1]-lv[1]-rv[1]);
	for(int i,x;q--;printf("%d\n",n-mv[1]-lv[1]-rv[1]))
		scanf("%d%d",&i,&x),ins(a[i],-1),s[a[i]].erase(i),ins(a[i],1),ins(x,-1),s[x].insert(i),ins(a[i]=x,1);
	return 0;
}