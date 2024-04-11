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
int n;
int head[200010],nxt[400010],to[400010];
int B,W;
int dep[200010];
int tot;
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if(dep[x]&1) ++B;
	else ++W;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		dfs(v,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%d\n",min(B,W)-1);
	return 0;
}