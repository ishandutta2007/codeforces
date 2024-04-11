#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,k;
int tot;
int head[110],nxt[210],to[210];
struct node{
	int a[41];
}f[110],pt;
const int mod=1e9+7;
void add(int u,int v){
	nxt[++tot]=head[u],head[u]=tot,to[tot]=v;
}
void dfs(int x,int fa){
	f[x].a[0]=f[x].a[k+1]=1;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		dfs(v,x);
		node tmp=pt;
		for(int a=0;a<=2*k;++a)
			for(int b=0;b<=2*k;++b){
				if(a+b>2*k) tmp.a[max(a,b+1)]=(tmp.a[max(a,b+1)]+1ll*f[x].a[a]*f[v].a[b]%mod)%mod;
				else tmp.a[min(a,b+1)]=(tmp.a[min(a,b+1)]+1ll*f[x].a[a]*f[v].a[b]%mod)%mod;
			}
		f[x]=tmp;
	}
}
int main(){
	n=read(),k=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=k;++i) ans=(ans+f[1].a[i])%mod;
	printf("%d\n",ans);
	return 0;
}