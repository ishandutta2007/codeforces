#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,m;
int col[300010],fa[300010];
vector<int>vec[300010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector<int>ans;
void dfs(int x,int fa){
	if(col[x]==1){
		ans.pb(x);
		for(int v:vec[x]) col[v]=0;
	}
	for(int v:vec[x]){
		if(v==fa) continue ;
		if(col[v]==-1){
			col[v]=1;dfs(v,x);
		}
		else if(col[x]) dfs(v,x);
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) col[i]=-1,vec[i].clear(),fa[i]=i;
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			vec[u].pb(v),vec[v].pb(u);
			int fx=find(u),fy=find(v);
			if(fx!=fy) fa[fx]=fy;
		}
		int cnt=0;
		for(int i=1;i<=n;++i) if(fa[i]==i) ++cnt;
		if(cnt>1){
			printf("NO\n");continue ;
		}
		ans.clear();col[1]=1;
		dfs(1,0);
		printf("YES\n%d\n",ans.size());
		for(int v:ans) printf("%d ",v);
		printf("\n");
	}
}