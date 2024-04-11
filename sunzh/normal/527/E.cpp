#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//#define pair<int,int> pair<int,int>
//#define first first
//#define second second 
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int ans;
int n,m;
vector<pair<int,int> >vec[500010];
pair<int,int> e[500010];
int a[500010],b[500010];
int deg[100010];
bool vis[100010],rev[100010];
vector<int>rt;
void dfs(int x,int fa){
	vis[x]=1;
	for(auto i:vec[x]){
		if(i.first==fa||vis[i.first]) continue ;
		if(e[i.second].second==x){
			swap(e[i.second].first,e[i.second].second);
		}
		dfs(i.first,x);
	}
}
void solve(int x,int fa){
	vis[x]=1;
	rev[x]=(deg[x]&1);
	for(auto i:vec[x]){
		if(i.first==fa||vis[i.first]) continue ;
		solve(i.first,x);
		if(rev[i.first]){
			swap(e[i.second].first,e[i.second].second);
			rev[x]^=1;
		}
	}
}
int main(){
	n=read(),m=read();
	ans=m;
	for(int i=1;i<=m;++i){
		a[i]=read(),b[i]=read();
		++deg[a[i]],++deg[b[i]];
	}
	int v=-1;
	for(int i=1;i<=n;++i){
		if(deg[i]&1){
			if(v==-1) v=i;
			else {
				a[++ans]=v,b[ans]=i; v=-1;
			}
		}
	}
	if(ans&1) a[++ans]=b[ans]=1;
	for(int i=1;i<=ans;++i){
		vec[a[i]].emplace_back(b[i],i);
		vec[b[i]].emplace_back(a[i],i);
		e[i]=make_pair(a[i],b[i]);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			rt.emplace_back(i);
			dfs(i,0);
		}
		deg[i]=0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=ans;++i){
		++deg[e[i].second];
	}
	for(auto i:rt){
		solve(i,0);
	}
	print(ans);putchar('\n');
	for(int i=1;i<=ans;++i) printf("%d %d\n",e[i].first,e[i].second);
	return 0;
}