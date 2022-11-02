#include<bits/stdc++.h>
const int N=1000000;
using namespace std;
int n,m,q,a0[N],a1[N],cnt;
struct T{
	int l,r,mn,ad;
	T*ls,*rs;
	void build(int,int);
	inline void add(int v){
		ad+=v,mn+=v;
	}
	inline void pd(){
		ls->add(ad),rs->add(ad);
		ad=0;
	}
	inline void upd(){
		mn=max(ls->mn,rs->mn);
	}
	void ins(int x,int v){
		if(r<=x)add(v);
		else if(l<=x)
		pd(),ls->ins(x,v),rs->ins(x,v),upd();
	}
	void qry(){
		if(l==r)printf("%d\n",l);
		else{
			pd();
			if(rs->mn>0)rs->qry();
			else ls->qry();
		}
	}
}b[N*2],*rt;
void T::build(int L,int R){
	l=L,r=R;
	if(l<r){
		int mi=l+r>>1;
		(ls=&b[cnt++])->build(l,mi);
		(rs=&b[cnt++])->build(mi+1,r);
	}
}
int op,x,y;
int main(){
	scanf("%d%d",&n,&m);
	(rt=&b[cnt++])->build(1,N);
	for(int i=1;i<=n;i++)
	scanf("%d",a0+i),rt->ins(a0[i],1);
	for(int i=1;i<=m;i++)
	scanf("%d",a1+i),rt->ins(a1[i],-1);
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&op,&x,&y);
		if(op>1)
		rt->ins(a1[x],1),rt->ins(a1[x]=y,-1);
		else
		rt->ins(a0[x],-1),rt->ins(a0[x]=y,1);
		if(rt->mn<=0)puts("-1");
		else rt->qry();
	}
}