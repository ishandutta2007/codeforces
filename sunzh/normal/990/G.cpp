#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int a[200010];
vector<int>vec[200010];
int fa[200010],siz[200010];
long long g[200010];
int mu[200010];
int p[200010],cnt;
bool vis[200010];
void getmu(int x){
	mu[1]=1;
	for(int i=2;i<=x;++i){
		if(!vis[i]) p[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&1ll*p[j]*i<=x;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break ;
			}
			else mu[i*p[j]]=-mu[i];
		}
	}
//	for(int i=1;i<=100;++i) printf("mu[%d]=%d\n",i,mu[i]);
}
vector<int>v[200010]; 
bool ins[200010];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy,siz[fy]+=siz[fx];
	}
} 
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),v[a[i]].pb(i);
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v);vec[v].pb(u);
	}
	getmu(200000);
	for(int i=200000;i>=1;--i){
		vector<int>nod;
		for(int j=1;j*i<=200000;++j){
			for(int k:v[j*i]){
				nod.pb(k);
			}
		} 
		for(int j:nod) fa[j]=j,siz[j]=1,ins[j]=1;
		for(int j:nod){
			for(int k:vec[j]){
				if(ins[k]) merge(k,j);
			}
		}
		for(int j:nod){
			if(fa[j]==j){
				g[i]+=(1ll*siz[j]*(siz[j]-1)>>1)+siz[j];
			}
		}
		for(int j:nod) ins[j]=0;
	}
	for(int i=1;i<=200000;++i){
		for(int j=2;j*i<=200000;++j){
			g[i]+=mu[j]*g[j*i];
		}
		if(g[i]) printf("%d %lld\n",i,g[i]);
	}
	return 0;
}