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
int n,m,mod;
char g[110][110];
int fa[20010];
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
struct matrix{
	int a[310][310];
	int pos[20010];
	int cnt; 
	int get(){
		bool f=0;
		int ans=1;
		for(int i=1;i<cnt;++i){
			int r=i;
			for(int j=i+1;j<cnt;++j) if(abs(a[j][i])>abs(a[r][i])) r=j;
			if(r!=i) f^=1;
			if(a[r][i]==0) return 0;
			for(int j=1;j<cnt;++j) swap(a[i][j],a[r][j]);
			int inv=qpow(a[i][i],mod-2);
			ans=1ll*ans*a[i][i]%mod;
			for(int j=i+1;j<cnt;++j){
				for(int k=i+1;k<cnt;++k){
					a[j][k]=(a[j][k]-1ll*a[j][i]*inv%mod*a[i][k]%mod+mod)%mod;
				}
			}
		}
		return f?(mod-ans)%mod:ans;
	}
}B,W;
void add(int x,int y){
	if(x==y) return ;
	int od=(x-1)/(m+1)+(x%(m+1)==0?m+1:x%(m+1));
	if(od&1){
		B.a[B.pos[x]][B.pos[y]]=(B.a[B.pos[x]][B.pos[y]]+mod-1)%mod;
		B.a[B.pos[y]][B.pos[x]]=(B.a[B.pos[y]][B.pos[x]]+mod-1)%mod;
		B.a[B.pos[x]][B.pos[x]]=(B.a[B.pos[x]][B.pos[x]]+1)%mod;
		B.a[B.pos[y]][B.pos[y]]=(B.a[B.pos[y]][B.pos[y]]+1)%mod;
	}
	else{
		W.a[W.pos[x]][W.pos[y]]=(W.a[W.pos[x]][W.pos[y]]+mod-1)%mod;
		W.a[W.pos[y]][W.pos[x]]=(W.a[W.pos[y]][W.pos[x]]+mod-1)%mod;
		W.a[W.pos[x]][W.pos[x]]=(W.a[W.pos[x]][W.pos[x]]+1)%mod;
		W.a[W.pos[y]][W.pos[y]]=(W.a[W.pos[y]][W.pos[y]]+1)%mod;
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy){
		printf("0\n");exit(0);
	}
	fa[fx]=fy;
}
int main(){
	n=read(),m=read(),mod=read();
	for(int i=1;i<=n;++i) scanf("%s",g[i]+1);
	for(int i=1;i<=(n+1)*(m+1);++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(g[i][j]=='/'){
				merge((i-1)*(m+1)+j+1,i*(m+1)+j);
			}
			if(g[i][j]=='\\'){
				merge((i-1)*(m+1)+j,i*(m+1)+j+1);
			}
		}
	}
	for(int i=1;i<=(n+1)*(m+1);++i) if(fa[i]==i) {if((i-1)/(m+1)+(i%(m+1)==0?m+1:i%(m+1))&1) B.pos[i]=++B.cnt;else W.pos[i]=++W.cnt;}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(g[i][j]=='*'){
				add(find((i)*(m+1)+j),find((i-1)*(m+1)+j+1));add(find((i)*(m+1)+j+1),find((i-1)*(m+1)+j));
			}
		} 
	}
	printf("%d\n",(B.get()+W.get())%mod);
	return 0;
}