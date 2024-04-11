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
int n;
int a[1000010];
vector<int>vec[1000010];
int deg[1000010];
bool del[1000010];
bool vis[1000010];
int stk[1000010];
int top;
void topo(){
	queue<int>Q;
	for(int i=1;i<=n;++i)
		if(!deg[i]){
			del[i]=1;Q.push(i);
		}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:vec[u]){
			if(!del[v]&&--deg[v]==0){
				Q.push(v);del[v]=1;
			}
		}
	}
}
bool fl;
void dfs(int x){
	if(fl) return ;
	if(vis[x]){
		fl=1;
		printf("%d\n",top);
		for(int i=1;i<=top;++i) printf("%d ",stk[i]);printf("\n");
		return ;
	}
	vis[x]=1;
	stk[++top]=x;
	for(int v:vec[x]){
		if(!del[v]) dfs(v);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) vec[i].clear(),deg[i]=vis[i]=stk[i]=del[i]=0;
		top=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
//			printf("i:%d,i-:%d\n",i,i-a[i]);
			vec[i].pb(i-a[i]);
			++deg[i-a[i]];
		}
		topo();
		for(int i=1;i<=n;++i){
			fl=0;
			if(!del[i]){
				dfs(i);
				break ;
			}
		}
	}
}