#include<bits/stdc++.h>
#define rg register int
#define mi (l+r>>1)
const int N=500005;
using namespace std;
char c;
inline void rd(int&x){
	for(;!isdigit(c=getchar()););
	for(x=c-48;isdigit(c=getchar());
	x=(x<<3)+(x<<1)+c-48);
}
int n,m,k,q,eu[N],ev[N],nxt[N],occ[N],
qu[N],qv[N],col[N],tot,ls[N<<2],L,R;
struct dat{
	int*x,y;
}st[N*3];
vector<int>op[N<<2];
inline void W(int&x,int y){
	st[tot++]={&x,x},x=y;
}
inline void ins(int k,int l,int r,int v){
	if(l>R||r<L)return;
	if(l>=L&&r<=R)//cerr<<'['<<l<<','<<r<<"].pb "<<v<<endl,
	op[k].push_back(v);
	else ins(k<<1,l,mi,v),ins(k<<1|1,mi+1,r,v);
}
struct ds{
	int f[N],sz[N],d[N];
	int rt(int x){
		for(;f[x];x=f[x]);
		return x;
	}
	bool rd(int x){
		rg re=0;
		for(;f[x];x=f[x])re^=d[x];
		return re;
	}
	inline bool uni(int x,int y){
		rg tx=rt(x),ty=rt(y);
		if(tx^ty){
			if(sz[tx]<sz[ty])
			swap(tx,ty);
			W(d[ty],rd(x)==rd(y));
			W(f[ty],tx),W(sz[tx],sz[tx]+sz[ty]);
			return 1;
		}return rd(x)^rd(y);
	}
}D[51];
void dfs(int k,int l,int r){
	//cerr<<"dfs :"<<"["<<l<<','<<r<<"]\n";
	ls[k]=tot;
	for(int i:op[k])//cerr<<qu[i]<<','<<qv[i]<<endl,
	assert(D[qv[i]].uni(eu[qu[i]],ev[qu[i]]));
	/*for(int i=1;i<=n;i++)
	for(int j=1;j<=::k;j++)
	if(D[j].f[i])cerr<<"("<<i<<','<<j<<")"<<D[j].f[i]<<endl;
	cerr<<endl;*/
	if(l<r)dfs(k<<1,l,mi),dfs(k<<1|1,mi+1,r);
	else{
		L=l+1,R=nxt[l];
		if(D[qv[l]].uni(eu[qu[l]],ev[qu[l]]))
		puts("YES"),col[qu[l]]=l,ins(1,1,q,l);
		else{
			puts("NO");
			if(col[qu[l]])
			ins(1,1,q,col[qu[l]]);
		}
	}
	for(;tot>ls[k];)
	tot--,*st[tot].x=st[tot].y;
}
int main(){
	rd(n),rd(m),rd(k),rd(q);
	for(rg i=1;i<=m;i++)
	rd(eu[i]),rd(ev[i]),occ[i]=q;
	for(rg i=1;i<=q;i++)rd(qu[i]),rd(qv[i]);
	for(rg i=q;i;i--)
	nxt[i]=occ[qu[i]],occ[qu[i]]=i-1;
	for(rg i=1;i<=k;i++)
	for(rg j=1;j<=n;j++)D[i].sz[j]=1;
	dfs(1,1,q);
}