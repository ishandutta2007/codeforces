#pragma GCC optimize(2)
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
int n;
int siz[100010];
int rt,idx;
long long res;
int ans[100010],pos[100010];
vector<int>vec[100010];
void dfs(int x,int fa){
	siz[x]=1;
	for(int i:vec[x]){
		if(i==fa) continue ;
		dfs(i,x);
		siz[x]+=siz[i];
	} 
	if(min(siz[x],n-siz[x])>min(siz[rt],n-siz[rt])) rt=x;
	res+=min(siz[x],n-siz[x]);
}
void dfs2(int x,int fa){
	pos[++idx]=x;
	for(int i:vec[x]){
		if(i==fa) continue ;
		dfs2(i,x);
	} 
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	dfs(1,0);
	dfs2(rt,0);
	printf("%lld\n",res<<1);
	for(int i=1;i<=idx;++i) ans[pos[i]]=pos[(i+(n>>1)-1)%n+1];
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
}