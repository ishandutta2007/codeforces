#include<cstdio>
#include<iostream>
#include<utility>
#include<cmath>
using namespace std;
const int o=2e6+10,inf=1e9;
inline int lowbit(int x){return x&-x;}
int n,a[o],ans;bool z=1;
struct FenwickTree{
	int b[o];
	inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) b[pos]+=val;}
	inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
}b1,b2;
struct segmenttree{
	int v1[o],v2[o],flg[o];pair<int,int> mn[o];
	inline void update(int id)
	{v1[id]=max(v1[id<<1],v1[(id<<1)|1]);v2[id]=min(v2[id<<1],v2[(id<<1)|1]);mn[id]=min(mn[id<<1],mn[(id<<1)|1]);}
	void build(int id,int l,int r){
		if(l==r){v1[id]=-inf;v2[id]=inf;mn[id]=make_pair(inf,l);return;}
		int md=l+r>>1;
		build(id<<1,l,md);build((id<<1)|1,md+1,r);
		update(id);
	}
	inline void ad(int id,int val){mn[id].first+=val;flg[id]+=val;}
	inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
	void modify1(int id,int ql,int qr,int val,int l=1,int r=n){
		if(ql>qr) return;
		if(ql<=l&&r<=qr){ad(id,val);return;}
		pushdown(id);
		int md=l+r>>1;
		if(ql<=md) modify1(id<<1,ql,qr,val,l,md);
		if(md<qr) modify1((id<<1)|1,ql,qr,val,md+1,r);
		update(id);
	}
	void modify2(int id,int pos,int val,int val1,int val2,int l=1,int r=n){
		if(l==r){v1[id]=val1;v2[id]=val2;mn[id].first=val;return;}
		pushdown(id);
		int md=l+r>>1;
		if(pos<=md) modify2(id<<1,pos,val,val1,val2,l,md);
		else modify2((id<<1)|1,pos,val,val1,val2,md+1,r);
		update(id);
	}
	int modify3(int id,int ql,int qr,int val,bool tp,int l=1,int r=n){
		if(ql>qr||val<=v2[id]) return val;
		if(l==r){
			int p=(tp?n-l+1:l);
			val=v2[id];mn[id].first=abs(a[p]-b2.query(a[p])-p+b1.query(p));v1[id]=val;v2[id]=inf;
			return val;
		}
		pushdown(id);
		int md=l+r>>1;
		if(md<qr) val=modify3((id<<1)|1,ql,qr,val,tp,md+1,r);
		if(ql<=md) val=modify3(id<<1,ql,qr,val,tp,l,md);
		update(id);
		return val;
	}
	int query1(int id,int val,int l=1,int r=n){
		if(val>v1[id]) return n+1;
		if(l==r) return l;
		pushdown(id);
		int md=l+r>>1;
		if(val<v1[id<<1]) return query1(id<<1,val,l,md);
		return query1((id<<1)|1,val,md+1,r);
	}
	int query2(int id,int pos,int l=1,int r=n){
		if(v1[id]==-inf) return n+1;
		if(l==r) return l;
		pushdown(id);
		int md=l+r>>1,t;
		if(pos<=md) if((t=query2(id<<1,pos,l,md))<=n) return t;
		return query2((id<<1)|1,pos,md+1,r);
	}
	int query3(int id,int pos,int l=1,int r=n){
		if(v1[id]==-inf) return 0;
		if(l==r) return l;
		pushdown(id);
		int md=l+r>>1,t;
		if(pos>md) if(t=query3((id<<1)|1,pos,md+1,r)) return t;
		return query3(id<<1,pos,l,md);
	}
}sgt1,sgt2;
int main(){
	scanf("%d",&n);a[n+1]=inf;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sgt1.build(1,1,n);sgt2.build(1,1,n);
	for(int i=1;i<=n;++i) if(i<a[i]) sgt1.modify2(1,i,inf,-inf,a[i]);else sgt2.modify2(1,n-i+1,inf,-inf,n-a[i]+1);
	sgt1.modify3(1,1,n,inf,0);sgt2.modify3(1,1,n,inf,1);
	for(int i=n,t,l,r;i--;){
		if(sgt1.mn[1]<sgt2.mn[1]) ans=max(ans,sgt1.mn[1].first),t=sgt1.mn[1].second,sgt1.modify2(z=1,t,inf,-inf,inf);
		else ans=max(ans,sgt2.mn[1].first),t=sgt2.mn[1].second,sgt2.modify2(1,t,inf,-inf,inf),t=n-t+1,z=0;
		b1.modify(t,1);b2.modify(a[t],1);
		l=sgt1.query1(1,a[t]);sgt1.modify1(1,l,t,-1);l=sgt2.query1(1,n-a[t]+1);sgt2.modify1(1,l,n-t+1,-1);
		if(z) l=sgt1.query3(1,t),r=sgt1.query2(1,t),sgt1.modify3(1,l+1,r-1,a[r],0);
		else l=sgt2.query3(1,n-t+1),r=sgt2.query2(1,n-t+1),sgt2.modify3(1,l+1,r-1,n-a[n-r+1]+1,1);
	}
	printf("%d",ans);
	return 0;
}