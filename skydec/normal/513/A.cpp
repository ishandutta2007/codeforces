#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
bool f[60][60];
bool vis[60][60];
int n1,n2,k1,k2;
bool dfs(int x,int y){
	if(!x&&!y)return 0;
	if(vis[x][y])return f[x][y];
	
	bool ff=0;
	
	for(int i=1;i<=min(k1,x);i++)if(!dfs(x-i,y))ff=1;
	
	for(int i=1;i<=min(k2,y);i++)if(!dfs(x,y-i))ff=1;
	
	return f[x][y]=ff;
}	
int main(){
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	//if(dfs(n1,n2))printf("First");
	//else printf("Second");
	
	if(n1>n2)printf("First");else printf("Second");
	return 0;
}