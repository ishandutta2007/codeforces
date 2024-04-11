#pragma GCC optimize(2,3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
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
typedef pair<int,PII>ppii;
int n,m,k;
struct node{
	ppii u;
	int dis;
	bool operator <(const node &x)const{
		return dis>x.dis;
	}
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dis[510][510][4];
int ds[22][510][510];
int ans[510][510];
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j){
			dis[i][j][2]=dis[i][j+1][3]=read();
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			dis[i][j][0]=dis[i+1][j][1]=read();
		}
	}
	memset(ds,0x3f,sizeof(ds));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) ds[0][i][j]=0;
	}
	if(k&1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j) printf("-1 ");
			printf("\n");
		}
		exit(0);
	}
	k>>=1;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			for(int l=1;l<=m;++l){
				for(int p=0;p<4;++p){
					int vx=j+dx[p],vy=l+dy[p];
					if(vx<1||vx>n||vy<1||vy>m) continue ;
					ds[i][j][l]=min(ds[i][j][l],ds[i-1][vx][vy]+dis[j][l][p]);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",ds[k][i][j]<<1);
		}
		printf("\n");
	}
}