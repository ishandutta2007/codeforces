#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int o=3e5+10;
int T,n,a[o],dis[o],st[o],tp,L1[o],L2[o],R1[o],R2[o],mn1[o*4],mn2[o*4];vector<int> v1[o],v2[o];
void build(int id,int l,int r){
	mn1[id]=mn2[id]=l;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
void modify1(int id,int pos,int val,int l=1,int r=n){
	if(l==r){mn1[id]=val;return;}
	int md=l+r>>1;
	if(pos<=md) modify1(id<<1,pos,val,l,md);
	else modify1((id<<1)|1,pos,val,md+1,r);
	mn1[id]=min(mn1[id<<1],mn1[(id<<1)|1]);
}
void modify2(int id,int pos,int val,int l=1,int r=n){
	if(l==r){mn2[id]=val;return;}
	int md=l+r>>1;
	if(pos<=md) modify2(id<<1,pos,val,l,md);
	else modify2((id<<1)|1,pos,val,md+1,r);
	mn2[id]=min(mn2[id<<1],mn2[(id<<1)|1]);
}
int query1(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return mn1[id];
	int md=l+r>>1;
	return min(ql<=md?query1(id<<1,ql,qr,l,md):o,md<qr?query1((id<<1)|1,ql,qr,md+1,r):o);
}
int query2(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return mn2[id];
	int md=l+r>>1;
	return min(ql<=md?query2(id<<1,ql,qr,l,md):o,md<qr?query2((id<<1)|1,ql,qr,md+1,r):o);
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",dis[n])){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),v1[i].clear(),v2[i].clear();
		st[tp=0]=0;
		for(int i=1;i<=n;L1[i]=st[tp]+1,st[++tp]=i++) for(;tp&&a[i]>a[st[tp]];--tp);
		st[tp=0]=0;
		for(int i=1;i<=n;L2[i]=st[tp]+1,st[++tp]=i++) for(;tp&&a[i]<a[st[tp]];--tp);
		st[tp=0]=n+1;
		for(int i=n;i;R1[i]=st[tp]-1,st[++tp]=i--) for(;tp&&a[i]>a[st[tp]];--tp);
		st[tp=0]=n+1;
		for(int i=n;i;R2[i]=st[tp]-1,st[++tp]=i--) for(;tp&&a[i]<a[st[tp]];--tp);
		build(1,1,n);
		for(int i=1;i<=n;++i){
			if(i>1){
				dis[i]=o;
				if(L1[i]<i) dis[i]=min(dis[i],query2(1,L1[i],i-1)+1);
				if(L2[i]<i) dis[i]=min(dis[i],query1(1,L2[i],i-1)+1);
			}
			modify1(1,i,dis[i]);modify2(1,i,dis[i]);
			v1[R1[i]].push_back(i);v2[R2[i]].push_back(i);
			for(int j=v1[i].size();j--;) modify1(1,v1[i][j],o);
			for(int j=v2[i].size();j--;) modify2(1,v2[i][j],o);
		}
	}
	return 0;
}