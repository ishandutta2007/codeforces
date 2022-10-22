#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define mn 505
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m,k,q;
int tol[mn][mn],tor[mn][mn],up[mn][mn],dw[mn][mn];
struct node{
	int x,y,z;
	node(){}
	node(int X,int Y,int Z){
		x=X;y=Y;z=Z;
	}
};
node Q[4005];
pii vis[mn][mn][15];
int f[mn][mn][15];
void bfs(int X,int Y){
	int l=1,r=0;
	Q[++r]=(node(X,Y,0));	
	pii tg=mp(X,Y);
	vis[X][Y][0]=tg;
	while(l<=r){
		node w=Q[l++];
		if(w.z==k)continue;
		int x=w.x,y=w.y,z=w.z;
		if(tol[x][y]&&(vis[x][y-1][z+1]!=tg||f[x][y-1][z+1]>f[x][y][z]+tol[x][y])){
			f[x][y-1][z+1]=f[x][y][z]+tol[x][y];
			if(vis[x][y-1][z+1]!=tg){
				vis[x][y-1][z+1]=tg;
				Q[++r]=(node(x,y-1,z+1));
			}
		}
		if(tor[x][y]&&(vis[x][y+1][z+1]!=tg||f[x][y+1][z+1]>f[x][y][z]+tor[x][y])){
			f[x][y+1][z+1]=f[x][y][z]+tor[x][y];
			if(vis[x][y+1][z+1]!=tg){
				vis[x][y+1][z+1]=tg;
				Q[++r]=(node(x,y+1,z+1));
			}
		}
		if(up[x][y]&&(vis[x-1][y][z+1]!=tg||f[x-1][y][z+1]>f[x][y][z]+up[x][y])){
			f[x-1][y][z+1]=f[x][y][z]+up[x][y];
			if(vis[x-1][y][z+1]!=tg){
				vis[x-1][y][z+1]=tg;
				Q[++r]=(node(x-1,y,z+1));
			}
		}
		if(dw[x][y]&&(vis[x+1][y][z+1]!=tg||f[x+1][y][z+1]>f[x][y][z]+dw[x][y])){
			f[x+1][y][z+1]=f[x][y][z]+dw[x][y];
			if(vis[x+1][y][z+1]!=tg){
				vis[x+1][y][z+1]=tg;
				Q[++r]=(node(x+1,y,z+1));
			}
		}
	}
}
int g[mn][mn],t[mn][mn];
signed main(){
	n=read();m=read();k=read();
	if(k%2==1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				printf("-1 ");
			}
			puts("");
		}
		return 0;
	}
	k>>=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j){
			tol[i][j+1]=tor[i][j]=read();
		}
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			up[i+1][j]=dw[i][j]=read();
	for(int tt=1;tt<=k;++tt){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				t[i][j]=g[i][j];	
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				g[i][j]=1e9;
				if(tol[i][j])g[i][j]=min(g[i][j],t[i][j-1]+tol[i][j]);
				if(tor[i][j])g[i][j]=min(g[i][j],t[i][j+1]+tor[i][j]);
				if(up[i][j])g[i][j]=min(g[i][j],t[i-1][j]+up[i][j]);
				if(dw[i][j])g[i][j]=min(g[i][j],t[i+1][j]+dw[i][j]);
			}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
	/*		bfs(i,j);
			int ans=1e9;
			for(int l=-k;l<=k;++l)
				for(int o=-k;o<=k;++o){
					if(i+l<1||i+l>n)continue;
					if(j+o<1||j+o>m)continue;
					if(vis[i+l][j+o][k]==mp(i,j))
					ans=min(ans,f[i+l][j+o][k]*2);
				}*/
			printf("%lld%c",g[i][j]*2,j==m?'\n':' ');
		}
	return 0;
}