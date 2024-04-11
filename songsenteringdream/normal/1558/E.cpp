#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=4010,inf=1e9+1;
int T,n,m,h[o],cnt,fr[o],a[o],b[o],st[o],pw;bool vis[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline void ins(int u){for(;!vis[u];u=fr[u]) pw+=b[u],pw=(pw>inf?inf:pw),vis[st[++cnt]=u]=1;}
bool dfs(int nw,int fa,long long val){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa&&val>a[e[i].v])
		if(vis[e[i].v]) if(vis[nw]);else{ins(nw);return true;}
		else if(fr[e[i].v]){ins(e[i].v);ins(nw);return true;}
		else if(dfs(e[i].v,fr[e[i].v]=nw,val+b[e[i].v])) return true;
	return false;
}
int main(){
	for(read(T);T--;){
		read(n);read(m);cnt=0;
		for(int i=1;i<=n;++i) h[i]=0;
		for(int i=2;i<=n;++i) read(a[i]);
		for(int i=2;i<=n;++i) read(b[i]); 
		for(int i,j;m--;) read(i),read(j),ad(i,j),ad(j,i);
		for(int l=0,r=inf,md;l<r;){
			for(int i=2;i<=n;++i) vis[i]=0;
			st[1]=vis[1]=cnt=1;
			pw=md=l+r>>1;
			for(bool flg;cnt<n;){
				for(int i=1;i<=n;++i) fr[i]=0;
				for(int i=flg=1;i<=cnt;++i) if(dfs(st[i],0,pw)){flg=0;break;}
				if(flg&&cnt<n){l=md+1;break;}
			}
			if(l<=md) r=md;
			if(l==r) printf("%d\n",l);
		}
	}
	return 0;
}