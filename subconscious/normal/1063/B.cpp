#include<bits/stdc++.h>
#define N 2015
using namespace std;
int U[4]={1,-1,0,0};
int V[4]={0,0,1,-1};
int f[N][N],g[N][N],n,m,r,c,P,Q;
short rx[N*N],ry[N*N];
char s[N][N];
bool check(int x,int y){
	return (x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='.');
}
int tot=0;
/*void dfs(int x,int y,int p,int q){
	tot++;
	//if (x==2&&y==2) printf("%d %d %d %d\n",x,y,p,q);
	if (f[x][y]<=p) return;
	f[x][y]=p;
	g[x][y]=q;
	for(int i=0;i<4;i++){	
		int nx=x+U[i],ny=y+V[i];
		//if (nx==lastx&&ny==lasty) continue;
		//printf("%c",s[nx][ny]);
		if (check(nx,ny)){
			if (i==2) dfs(nx,ny,p,q+1); else
			if (i==3) dfs(nx,ny,p+1,q); else dfs(nx,ny,p,q);
		}
	}
}*/
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&P,&Q);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	//f[r][c]=g[r][c]=1;
	int tou=0,wei=1;
	rx[1]=r; ry[1]=c; f[r][c]=g[r][c]=0;
	while(tou!=wei){
		tou++; if(tou>n*m)tou=1;
		int x=rx[tou],y=ry[tou];
		//printf("%d %d\n",x,y);
		for (int i=0;i<4;i++){
			int nx=x+U[i],ny=y+V[i];
			if (check(nx,ny)){
				int p=f[x][y];
				int q=g[x][y];
				if (i==2) q++; 
				if (i==3) p++;
				if (i>=2&&f[nx][ny]>p){
					f[nx][ny]=p;
					g[nx][ny]=q;
					wei++;if(wei>n*m)wei=1;
					rx[wei]=nx;
					ry[wei]=ny;
				} else
				if (i<2&&f[nx][ny]>p){
					f[nx][ny]=p;
					g[nx][ny]=q;
					rx[tou]=nx;
					ry[tou]=ny;
					tou--;if(tou==0)tou=n*m;
				}
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if(f[i][j]<=P&&g[i][j]<=Q) ans++;
	//f[r][c]=g[r][c]=1;
	cout<<ans<<endl;
	//cout<<tot<<endl;
}