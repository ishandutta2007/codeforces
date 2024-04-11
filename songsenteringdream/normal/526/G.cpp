#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;}
inline long long Max(long long a,long long b){return a>b?a:b;}
const int o=5e5+10;
int n,m,h[o],cnt;long long ans;
struct Edge{int v,p,w;}e[o*2];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
inline bool cmp1(int A,int B);
inline bool cmp2(int A,int B);
struct Tree{
	int rt,iden,anc[o][20],hs[o],rk[o],p[o],cnt,val;long long dis[o],mxd[o],ans[o],tp[o];
	void Dfs(int nw,int fa){
		anc[nw][0]=fa;
		for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
			dis[e[i].v]=dis[nw]+e[i].w,Dfs(e[i].v,nw),hs[nw]=(mxd[e[i].v]>mxd[hs[nw]]?e[i].v:hs[nw]);
		if(hs[nw]) mxd[nw]=mxd[hs[nw]];else mxd[nw]=dis[nw];
	}
	void dfs(int nw,int fa,int ld){
		if((tp[nw]=ld)==nw) p[++cnt]=nw;
		if(hs[nw]) dfs(hs[nw],nw,ld);
		for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa&&e[i].v-hs[nw]) dfs(e[i].v,nw,e[i].v);
	}
	inline void init(int bg){
		Dfs(bg,0);
		for(int i=1;i<=n;mxd[i]=hs[i]=0,++i) if(dis[i]>dis[rt]) rt=i;
		Dfs(rt,dis[rt]=0);dfs(rt,0,rt);
		for(int i=1;i<20;++i) for(int j=1;j<=n;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
		if(iden<2) sort(p+1,p+cnt+1,cmp1);else sort(p+1,p+cnt+1,cmp2);
		for(int i=1;i<=cnt;++i) rk[p[i]]=i,ans[i]=ans[i-1]+mxd[p[i]]-dis[anc[p[i]][0]];
	}
	inline long long ask(int a,int k,bool op=0){
		long long res=mxd[a]+ans[k];
		for(int i=19;i+1;--i) if(rk[tp[anc[a][i]]]>k) a=anc[a][i];
		return res-dis[anc[a][0]]-(op?mxd[anc[a][0]]-dis[anc[a][0]]:0);
	}
	inline long long query(int a,int k){
		if(rk[tp[a]]>k) return Max(ask(a,k-1),ask(a,k,1));
		return ans[Min(k,cnt)];
	}
}T1,T2;
inline bool cmp1(int A,int B){return T1.mxd[A]-T1.dis[T1.anc[A][0]]>T1.mxd[B]-T1.dis[T1.anc[B][0]];}
inline bool cmp2(int A,int B){return T2.mxd[A]-T2.dis[T2.anc[A][0]]>T2.mxd[B]-T2.dis[T2.anc[B][0]];}
int main(){
	read(n);read(m);
	for(int i=1,j,k,$;i<n;++i) read(j),read(k),read($),ad(j,k,$),ad(k,j,$);
	T1.iden=1;T2.iden=2;T1.init(1);T2.init(T1.rt);
	for(int a,k;m--;printf("%lld\n",ans=Max(T1.query(a,2*k-1),T2.query(a,2*k-1))))
		read(a),read(k),a=(a+ans-1)%n+1,k=(k+ans-1)%n+1;
	return 0;
}