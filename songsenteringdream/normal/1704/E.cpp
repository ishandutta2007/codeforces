#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
const int o=1010,MOD=998244353,inf=1e9;
int T,n,m,d[o],h[o],cnt,tot[o],a[o],ans,lst;pair<int,pair<int,int> > p[o][o*4],z[o*4];queue<int> q;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",z[cnt].second.second)){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),h[i]=tot[i]=0;
		for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),ad(u,v),++d[v];
		for(int i=1;i<=n;++i) if(!d[i]) q.push(i);
		for(int u;!q.empty();q.pop()){
			u=q.front();sort(p[u]+1,p[u]+tot[u]+1);cnt=0;
			if(a[u]) z[cnt=1]=make_pair(1,make_pair(a[u],a[u]%MOD));
			for(int i=1;i<=tot[u];++i)
				if(cnt&&z[cnt].second.first>=p[u][i].first)
					z[cnt].second.first=min(inf,z[cnt].second.first+p[u][i].second.first-p[u][i].first+1),
					z[cnt].second.second=(z[cnt].second.second+(p[u][i].second.second+MOD-p[u][i].first+1)%MOD)%MOD;
				else
					z[++cnt]=p[u][i],++z[cnt].first,z[cnt].second.first=min(inf,z[cnt].second.first+1),
					z[cnt].second.second=(z[cnt].second.second+1)%MOD;
			for(int i=h[u];i;i=e[i].p){
				for(int j=1;j<=cnt;++j) p[e[i].v][++tot[e[i].v]]=z[j];
				if(!--d[e[i].v]) q.push(e[i].v);
			}
		}
	}
	return 0;
}