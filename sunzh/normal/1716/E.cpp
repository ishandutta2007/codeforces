#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,N;
int a[1<<18|1];
int q;
struct node{
	int lmx,rmx,su,mx;
};
vector<node>sgt[1<<20];
node merge(node x,node y){
	return node{max(x.lmx,x.su+y.lmx),max(y.rmx,y.su+x.rmx),x.su+y.su,max(max(x.mx,y.mx),x.rmx+y.lmx)};
}
void build(int p,int l,int r,int bt){
	if(l==r){
		int m=max(a[l],0ll);
		sgt[p].pb(node{m,m,a[l],m});return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid,bt-1);build(p<<1|1,mid+1,r,bt-1);
	sgt[p].assign((1<<bt),node{0,0,0,0});
	for(int i=0;i<(1<<bt-1);++i){
		sgt[p][i]=merge(sgt[p<<1][i],sgt[p<<1|1][i]);
		sgt[p][i|(1<<bt-1)]=merge(sgt[p<<1|1][i],sgt[p<<1][i]);
	}
	vector<node>().swap(sgt[p<<1]);
	vector<node>().swap(sgt[p<<1|1]);
}
signed main(){
	n=read();N=(1<<n);
	for(int i=1;i<=N;++i) a[i]=read();
	// for(int i=0;i<n;++i){
	// 	for(int j=1;j+(1<<i)<=N;++j){
	// 		st[i].insert(j);
	// 	}
	// }
	q=read();
	build(1,1,N,n);
	int nw=0;
	while(q--){
		int k=read();nw^=(1<<k);
		printf("%lld\n",sgt[1][nw].mx);
		// if(st)
	}
}