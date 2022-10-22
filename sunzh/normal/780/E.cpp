#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m,k;
int fa[200010];
vector<int>vec[200010];
vector<int>ans,out[200010];
void dfs(int x,int f){
	ans.pb(x);
	for(int i:vec[x]){
		if(i==f) continue ;
		dfs(i,x);
		ans.pb(x);
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
//	freopen("clone.in","r",stdin);
//	freopen("clone.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		int fx=find(u),fy=find(v);
		if(fx!=fy) fa[fx]=fy,vec[u].pb(v),vec[v].pb(u);
	}
	dfs(1,0);
	int sz=ceil((n<<1)*1.0/k);
//	printf("YES\n");
	for(int i=0;i<ans.size();++i){
		out[i/sz].pb(ans[i]);
	}
	for(int i=0;i<k;++i){
		if(out[i].size()==0) out[i].pb(1);
		printf("%d ",out[i].size());
		for(int v:out[i]) printf("%d ",v);
		printf("\n");
	}
	return 0;
}