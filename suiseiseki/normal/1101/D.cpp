#include <cstdio>
#include <vector>
using namespace std;
#define Maxn 200000
vector<int> p[Maxn+5],c[Maxn+5],e[Maxn+5];
int n;
void work(int x,int t){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			p[t].push_back(i);
			c[t].push_back(1);
			while(x%i==0){
				x/=i;
			}
		}
	}
	if(x>1){
		p[t].push_back(x);
		c[t].push_back(1);
	}
}
int ans=1;
int mx(int a,int b){
	return a>b?a:b;
}
void update(int x,int y){
	for(int i=0;i<(int)p[x].size();i++){
		for(int j=0;j<(int)p[y].size();j++){
			if(p[x][i]==p[y][j]){
				ans=mx(ans,c[x][i]+c[y][j]);
				c[x][i]=mx(c[x][i],c[y][j]+1);
			}
		}
	}
}
void dfs(int x,int fa){
	for(int i=0;i<(int)e[x].size();i++){
		if(e[x][i]==fa){
			continue;
		}
		dfs(e[x][i],x);
		update(x,e[x][i]);
	}
}
int main(){
	scanf("%d",&n);
	int x;
	bool flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		work(x,i);
		if(x!=1){
			flag=1;
		}
	}
	if(!flag){
		puts("0");
		return 0;
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}