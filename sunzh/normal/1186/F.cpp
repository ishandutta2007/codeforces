#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
int deg[1000010];
int cnt;
vector<PII>ans;
vector<int>Eular; 
vector<PII>vec[1000010];
int num[1000010];
bool used[3000010];
int fa[1000010];
struct edge{
	int u,v;
}e[1000010];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x,int id){
	while(num[x]<deg[x]){
		PII v=vec[x][num[x]];
		++num[x];
		if(used[v.se]) continue ;
		used[v.se]=1;
		dfs(v.fi,v.se);
	}
	if(id!=-1) Eular.pb(id);
}
int main(){
	n=read(),m=read();
	cnt=m;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		e[i]=edge{u,v};
		vec[u].pb(mp(v,i));vec[v].pb(mp(u,i));
		++deg[u],++deg[v];
		fa[find(u)]=find(v);
	}
	for(int i=1;i<=n;++i){
		if((deg[i]&1)^1){
			deg[i]+=2;deg[0]+=2; 
			vec[0].ep(i,++cnt);
			vec[i].ep(0,cnt);
			vec[0].ep(i,++cnt);
			vec[i].ep(0,cnt);
			fa[find(i)]=0;
		}
		else if(deg[i]&1){
			++deg[0];++deg[i];
			vec[0].ep(i,++cnt);
			vec[i].ep(0,cnt);fa[find(i)]=0;
		}
		else if(find(i)==i){
			deg[i]+=2;deg[0]+=2; 
			vec[0].ep(i,++cnt);
			vec[i].ep(0,cnt);
			vec[0].ep(i,++cnt);
			vec[i].ep(0,cnt);
			fa[find(i)]=0;
		}
	}
	if(cnt==m){
		deg[0]+=2,deg[1]+=2; 
		vec[0].ep(1,++cnt);
		vec[1].ep(0,cnt);
		vec[0].ep(1,++cnt);
		vec[1].ep(0,cnt);
	}
	dfs(0,-1);
	cnt=0;
	for(int i=0;i<Eular.size();++i){
		int x=Eular[i];
		if(x>m||x==-1) continue ;
		if(!(i&1)){
			ans.ep(e[x].u,e[x].v);++cnt;
		}
		else if(i&&Eular[i-1]>m){
			ans.ep(e[x].u,e[x].v);++cnt;
		}
		else if(i+1<Eular.size()&&Eular[i+1]>m){
			ans.ep(e[x].u,e[x].v);++cnt;
			Eular[i+1]=-1;
		}
	}
	printf("%d\n",cnt);
	for(auto i:ans){
		printf("%d %d\n",i.fi,i.se);
	}
	return 0;
}