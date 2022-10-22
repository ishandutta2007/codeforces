#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<bitset>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
bool d[210][210][210];
char str[210];
vector<int>ve[210][210];
bitset<210>bt[210][210];
vector<int>vec[210];
bool edg[210][210];
int fa[210];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(){
	// printf("!!\n");
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j) if(edg[i][j]){
			// printf("%d %d\n",i,j);
			int fx=find(i),fy=find(j);
			if(fx==fy) return 0;
			fa[fx]=fy;
		}
	}
	return 1;
}
int dis[210][210];
bool check2(){
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dis[i][j]=-1;
	for(int i=1;i<=n;++i){
		queue<int>Q;dis[i][i]=0;Q.push(i);
		// printf("i:%d\n",i);
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			// printf("u:%d,%d\n",u,dis[i][u]);
			for(int v:vec[u]){
				// printf("v:%d,%d\n",v,dis[i][v]);
				if(dis[i][v]==-1){
					// printf("v:%d\n",v);
					dis[i][v]=dis[i][u]+1;Q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=i+1;k<=n;++k) {
				if(d[i][j][k]!=(dis[j][i]==dis[j][k])){
					// printf("%d %d %d,%d %d\n",i,j,k,dis[j][i],dis[j][k]);
					return 0;
				}
			}
		}
	}
	return 1;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ve[i][j].clear();
		for(int i=1;i<n;++i){
			for(int j=1;j<=n-i;++j){
				scanf("%s",str+1);
				for(int k=1;k<=n;++k){
					d[i][k][i+j]=d[i+j][k][i]=str[k]-'0';
					if(str[k]=='1'){
						// printf("%d %d %d\n",i,j,k);
						ve[i][k].pb(i+j);ve[i+j][k].pb(i);
					}
				}
			}
		}
		bool fl=0;
		for(int i=2;i<=n;++i){
			for(int j=1;j<=n;++j) vec[j].clear();
			for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) edg[j][k]=0;
			edg[1][i]=edg[i][1]=1;
			queue<PII>Q;Q.push(mp(1,i));
			int cnt=0;
			// printf("i:%d\n",i);
			// printf("i:%d\n",i);
			while(!Q.empty()){
				PII u=Q.front();Q.pop();
				vec[u.fi].pb(u.se);vec[u.se].pb(u.fi);
				// printf("%d %d\n",u.fi,u.se);
				++cnt;
				// printf("%d %d\n",u.fi,u.se);
				for(int j:ve[u.fi][u.se]){
					if(!edg[u.se][j]){
						edg[u.se][j]=edg[j][u.se]=1;
						Q.push(mp(u.se,j));
					}
				}
				for(int j:ve[u.se][u.fi]){
					if(!edg[u.fi][j]){
						edg[u.fi][j]=edg[j][u.fi]=1;
						Q.push(mp(u.fi,j));
					}
				}
			}
			// printf("cnt:%d\n",cnt);
			if(cnt==n-1){
				if(check()&&check2()){
					fl=1;
					printf("Yes\n");
					for(int j=1;j<=n;++j) for(int k=j+1;k<=n;++k) if(edg[j][k]) printf("%d %d\n",j,k);
					// cerr<<"do";
					break ;
				}
			}
		}
		// cerr<<"exit";
		if(!fl) printf("No\n");
	}
}