#include<cstdio>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
const int o=4e5+10,inf=(1e9)+o;
int T,n,q,p,a[o],ans,s[o],flg[o];priority_queue<int> Q;pair<int,int> mn[o];
void build(int id,int l,int r){
	flg[id]=0;
	if(l==r){mn[id]=make_pair(q-a[l],l);return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
inline void ad(int id,int val){flg[id]+=val;mn[id].first+=val;}
inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
void modify(int id,int ql,int qr,int val,int l=1,int r=n){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
pair<int,int> query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return mn[id];
	pushdown(id);
	int md=l+r>>1;
	if(qr<=md) return query(id<<1,ql,qr,l,md);
	if(md<ql) return query((id<<1)|1,ql,qr,md+1,r);
	return min(query(id<<1,ql,qr,l,md),query((id<<1)|1,ql,qr,md+1,r));
}
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%d",&n,&q);ans=-1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+(a[i]<=q);
		if(q>=n){for(int i=1;i<=n;++i) putchar(49);continue;}
		for(build(1,1,n);!Q.empty();Q.pop());
		for(int i=1;i<=q;++i) Q.push(n);
		for(int i=n;i;--i){
			for(pair<int,int> pr;(pr=query(1,i,n)).first<0;)
				Q.push(pr.second),modify(1,pr.second,n,-1),modify(1,pr.second,pr.second,inf);
			for(;Q.size()>q;Q.pop());
			if(s[i-1]+Q.top()-i+1>ans) ans=s[p=i-1]+Q.top()-i+1;
		}
		if(s[n]>ans) ans=s[p=n];
		for(int i=1;i<=p;++i) putchar(48+(a[i]<=q));
		for(int i=p+1;i<=n;++i) if(q) putchar(49),q-=(a[i]>q);else putchar(48);
	}
	return 0;
}