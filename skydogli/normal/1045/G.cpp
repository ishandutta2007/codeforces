#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define MN 100005
int sum[MN<<6],ls[MN<<6],rs[MN<<6],cnt,n,k,v[MN],root[MN];
long long ans;
inline int read(){
	int a=0;char c=getchar();
	while(c>57 or c<48)c=getchar();
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
struct data{
	int x,r,q;
	bool friend operator<(data a,data b){
		return a.r>b.r;
	}
}w[MN];
int query(int x,int l,int r,int b,int e){
	if(!x||r<b||l>e)return 0;
	if(b<=l&&r<=e) return sum[x];
	int mid=(l+r)>>1;
	return query(ls[x],l,mid,b,e)+query(rs[x],mid+1,r,b,e);
}
void Ins(int &x,int l,int r,int loc){
	if(!x) x=++cnt;
	sum[x]++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(loc<=mid) Ins(ls[x],l,mid,loc);
		else Ins(rs[x],mid+1,r,loc);
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i){
		w[i].x=read();
		w[i].r=read();
		v[i]=w[i].q=read();
	}
	sort(v+1,v+1+n);
	sort(w+1,w+1+n);
	int N=unique(v+1,v+1+n)-v;
	for(int i=1;i<=n;++i){
		w[i].q=lower_bound(v+1,v+N,w[i].q)-v;
		for(int j=w[i].q;j;--j){
			if(v[w[i].q]-v[j]>k) break;	
			ans+=query(root[j],0,INF,w[i].x-w[i].r,w[i].x+w[i].r);
		}
		for(int j=w[i].q+1;j<N;++j){
			if(v[j]-v[w[i].q]>k)break;
			ans+=query(root[j],0,INF,w[i].x-w[i].r,w[i].x+w[i].r);
		}
		Ins(root[w[i].q],0,INF,w[i].x);
	}
	printf("%I64d\n",ans);
	return 0;
}