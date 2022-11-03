/*
ID: Sfiction
OJ: ZOJ
PROB: 500B
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=400;

int n;
int num[MAXN];

int fa[MAXN];
char map[MAXN][MAXN];
bool vis[MAXN];
int list[MAXN];

int root(int x){
	return fa[x]==x ? x : (fa[x]=root(fa[x]));
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&num[i]);
		fa[i]=i;
	}
	for (int i=0;i<n;++i){
		scanf("%s",map[i]);
		for (int j=0;j<n;++j)
			if (map[i][j]=='1')
				fa[root(i)]=fa[root(j)];
	}
	memset(vis,0,sizeof(vis));
	for (int i=0;i<n;++i)
		if (!vis[i]){
			int u=root(i),m=1;

			list[0]=num[i];
			for (int j=i+1;j<n;++j)
				if (u==root(j)){
					vis[j]=true;
					list[m++]=num[j];
				}
			sort(list,list+m);
			for (int j=n-1;j>=i;--j)
				if (u==root(j))
					num[j]=list[--m];
		}
	printf("%d",num[0]);
	for (int i=1;i<n;++i)
		printf(" %d",num[i]);
	return 0;
}