#include <queue>
#include <cstdio>

#define rep(i,j,k) for (int i=j;i<=k;++i)

using namespace std;

const int N=(int)2e3,dx[]={0,0,1,-1},dy[]={1,-1,0,0};

queue<int> Q;
char a[N+10][N+10];
int n,m,deg[N+10][N+10];

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m){
		char ch=getchar();
		while (ch!='.' && ch!='*') ch=getchar();
		a[i][j]=ch;
	}
	rep(i,1,n) rep(j,1,m) if (a[i][j]=='.') rep(k,0,3) if (a[i+dx[k]][j+dy[k]]=='.'){
		deg[i][j]++;
		deg[i+dx[k]][j+dy[k]]++;
	}
	rep(i,1,n) rep(j,1,m) deg[i][j]/=2;
	rep(i,1,n) rep(j,1,m) if (deg[i][j]==1){
		Q.push(i);
		Q.push(j);
	}
	while (!Q.empty()){
		int i=Q.front();
		Q.pop();
		int j=Q.front();
		Q.pop();
		int x,y;
		rep(k,0,3){
			int tx=i+dx[k],ty=j+dy[k];
			if (a[tx][ty]=='.'){
				if (i==tx){
					if (j<ty){
						a[i][j]='<';
						a[tx][ty]='>';
					}
					else{
						a[tx][ty]='<';
						a[i][j]='>';
					}
                                }
				else {if (i<tx){
						a[i][j]='^';
						a[tx][ty]='v';
					}
					else{
						a[tx][ty]='^';
						a[i][j]='v';
					}
                                  }
				x=tx;
				y=ty;
			}
		}
		rep(k,0,3){
			int tx=x+dx[k],ty=y+dy[k];
			if (a[tx][ty]=='.'){
				deg[tx][ty]--;
				if (deg[tx][ty]==1){
					Q.push(tx);
					Q.push(ty);
				}
			}
		}
                x=i;y=j;
                rep(k,0,3){
			int tx=x+dx[k],ty=y+dy[k];
			if (a[tx][ty]=='.'){
				deg[tx][ty]--;
				if (deg[tx][ty]==1){
					Q.push(tx);
					Q.push(ty);
				}
			}
		}
	}
	rep(i,1,n) rep(j,1,m) if (a[i][j]=='.'){
		puts("Not unique");
		return 0;
	}
	rep(i,1,n) rep(j,1,m) printf("%c%s",a[i][j],j==m?"\n":"");
	return 0;
}