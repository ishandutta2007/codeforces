#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=500000;
int n,m,t,d[Maxn+5],vis[Maxn+5],a[Maxn+5],f[Maxn+5],p[Maxn+5],q[Maxn+5];
int Find(int x){
	if(f[x]==0){
		return x;
	}
	return f[x]=Find(f[x]);
}
vector<int> g[Maxn+5],c[Maxn+5],w[Maxn+5];
void dfs(int i,int fa){
	vis[i]=1;
	for(auto j:c[i]){
		if(j!=fa){
			dfs(j,i);
			if(w[j].empty()){
				w[i].push_back(j);
			}
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			vis[i]=d[i]=f[i]=0;
			g[i].clear();
			c[i].clear();
			w[i].clear();
		}
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			d[u]++;
			d[v]++;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1,j;i<=n;i++){
			if(d[i]!=n-1){
				int k=0;
				for(auto it:g[i]){
					a[++k]=it;
				}
				a[++k]=i;
				sort(a+1,a+1+k);
				for(j=1;j<=k;j++){
					if(j!=a[j]){
						break;
					}
				}
				int x=Find(i),y=Find(j);
				if(x!=y){
					f[x]=y;
					c[i].push_back(j);
					c[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!c[i].empty()&&!vis[i]){
				dfs(i,0);
				if(w[i].empty()){
					w[c[i][0]].push_back(i);
				}
			}
		}
		int k=0;
		for(int i=1;i<=n;i++){
			if(c[i].empty()){
				p[i]=++k;
				q[i]=k;
			}
			else{
				if(!w[i].empty()){
					for(int j=0;j<(int)w[i].size();j++){
						p[w[i][j]]=j+k+1;
					}
					p[i]=w[i].size()+k+1;
					q[i]=k+1;
					for(int j=0;j<(int)w[i].size();j++){
						q[w[i][j]]=j+k+2;
					}
					k+=w[i].size()+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",p[i]);
		}
		puts("");
		for(int i=1;i<=n;i++){
			printf("%d ",q[i]);
		}
		puts("");
	}
}