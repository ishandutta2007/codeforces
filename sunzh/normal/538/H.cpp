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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int N1,N2;
int t,T;
int n,m;
vector<int>vec[100010]; 
int l[100010],r[100010];
int col[100010];
int fa[100010];
vector<int>st[100010];
bool dfs(int x,int fa,bool cl){
	if(cl==0){
		if(l[x]>N1||r[x]<N1){
//			if(n==100000) printf("x:%d,%d %d %d\n",x,l[x],r[x],N2);
			return 0;
		}
	}
	else {
		if(l[x]>N2||r[x]<N2){
//			if(n==100000) printf("x:%d,%d %d %d\n",x,l[x],r[x],N2);
			return 0;
		}
	}
	col[x]=cl;
	bool f=1;
	for(int v:vec[x]){
//		printf("x:%d,v:%d\n",x,v);
//		if(v==fa) continue ;
		if(col[v]!=-1){
			if(col[v]==col[x]){
//				if(n==100000) printf("x:%d,v:%d\n",x,v);
//				if(n==100000) printf("%d %d %d %d\n",l[x],r[x],l[v],r[v]);
				return 0;
			}
		}
		else f=f&dfs(v,x,cl^1);
		if(!f) return 0;
	}
	return f;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	t=read(),T=read();
	n=read(),m=read();
	for(int i=1;i<=n;++i) l[i]=read(),r[i]=read();
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
		int fx=find(u),fy=find(v);
		fa[fx]=fy;
	}
	for(int i=1;i<=n;++i){
		st[find(i)].pb(i);
	}
	N1=0x3f3f3f3f,N2=0;
	for(int i=1;i<=n;++i) N1=min(N1,r[i]),N2=max(N2,l[i]);
	if(N1+N2<t){
		N2+=t-N1-N2;
	}
	else if(N1+N2>T){
		N1-=N1+N2-T;
	}
//	if(n==100000){
//		printf("%d %d\n",N1,N2);
//	}
	if(N1<0||N2<0){
		printf("IMPOSSIBLE\n");exit(0);
	}
//	printf("%d %d\n",N1,N2);
	for(int i=1;i<=n;++i){
		if(l[i]>N1||r[i]<N1){
			if(l[i]>N2||r[i]<N2){
//				if(n==100000){
//					printf("aead\n");
//				}
				printf("IMPOSSIBLE\n",i);exit(0);
			}
		}
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;++i){
		if(col[i]==-1){
			if(l[i]>N1||r[i]<N1){
				col[i]=1;
			}
			else if(l[i]>N2||r[i]<N2){
				col[i]=0;
			}
		}
//		printf("col[%d]=%d\n",i,col[i]);
	}
	for(int i=1;i<=n;++i){
		if(col[i]!=-1){
			if(!dfs(i,0,col[i])){
//				if(n==100000){
//					printf("%d %d %d\n",i,l[i],r[i]);
//				}
				printf("IMPOSSIBLE\n");exit(0);
			}
		}
	}
	for(int i=1;i<=n;++i) if(col[i]==-1) if(!dfs(i,0,0)){printf("IMPOSSIBLE\n");exit(0);}
	printf("POSSIBLE\n");
	printf("%d %d\n",N1,N2);
	for(int i=1;i<=n;++i) putchar('1'+col[i]);
}