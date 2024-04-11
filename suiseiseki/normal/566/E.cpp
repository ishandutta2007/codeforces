#include <bitset>
#include <cstdio>
using namespace std;
const int Maxn=1000;
const int Inf=0x3f3f3f3f;
bitset<Maxn+5> g[Maxn+5],s[Maxn+5],nl;
int n,fa[Maxn+5];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);
			g[i][x]=1;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	bitset<Maxn+5> t;
	int u=0,v=0,cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t=(g[i]&g[j]);
			if(t.count()==2){
				u=t._Find_first();
				v=t._Find_next(u);
				int fa_u=find(u),fa_v=find(v);
				if(fa_u!=fa_v){
					fa[fa_u]=fa_v;
					printf("%d %d\n",u,v);
					cnt++;
					s[u][u]=s[v][v]=s[u][v]=s[v][u]=1;
					nl[u]=nl[v]=1;
				}
			}
		}
	}
	if(cnt==0){
		for(int i=2;i<=n;i++){
			printf("1 %d\n",i);
		}
	}
	else if(cnt==1){
		for(int i=1;i<=n;i++){
			if((int)g[i].count()<n){
				for(int j=1;j<=n;j++){
					if(!nl[j]){
						printf("%d %d\n",(g[i][j]?u:v),j);
					}
				}
				break;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!nl[i]){
				int minn=Inf;
				for(int j=1;j<=n;j++){
					if(g[j][i]&&(int)(g[j]&nl).count()<minn){
						t=(g[j]&nl);
						minn=t.count();
					}
				}
				for(int j=1;j<=n;j++){
					if(t[j]&&s[j]==t){
						printf("%d %d\n",i,j);
						break;
					}
				}
			}
		}
	}
	return 0;
}