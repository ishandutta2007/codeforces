#include <cstdio>
#include <vector>
using namespace std;
#define Maxn 1000
int n,val,sum,uu,vv;
vector<int> edge[Maxn+5];
int mp[Maxn+5][Maxn+5];
int cmp,num1,num2,num3,num4;
vector<int> ans[4];
void f(int x,int y,int z){
	if(x!=y&&z){
		ans[1].push_back(x);
		ans[2].push_back(y);
		ans[3].push_back(z);
	}
}
void dfs(int x,int fa){
	if(edge[x].size()==1){
		if(!uu){
			uu=x;
		}
		vv=x;
	}
	int v;
	for(int i=0;i<(int)edge[x].size();i++){
		v=edge[x][i];
		if(v==fa){
			continue;
		}
		dfs(v,x);
	}
}
int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&val);
		edge[u].push_back(v);
		edge[v].push_back(u);
		mp[u][v]=mp[v][u]=val;
	}
	for(int i=1;i<=n;i++){
		if(edge[i].size()==2){
			puts("NO");
			return 0;
		}
	}
	int value;
	int V;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)edge[i].size();j++){
			V=edge[i][j];
			if(i>V){
				continue;
			}
			value=mp[i][V];
			uu=vv=0;
			dfs(i,V);
			num1=uu;
			num2=vv;
			uu=vv=0;
			dfs(V,i);
			num3=uu;
			num4=vv;
			f(num1,num3,value>>1);
			f(num2,num4,value>>1);
			f(num1,num2,-(value>>1));
			f(num3,num4,-(value>>1));
		}
	}
	puts("YES");
	printf("%d\n",ans[1].size()); 
	for(int i=0;i<(int)ans[1].size();i++){
		printf("%d %d %d\n",ans[1][i],ans[2][i],ans[3][i]);
	}
	return 0;
}