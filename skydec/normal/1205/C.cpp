#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
int n;
bool ask(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x;scanf("%d",&x);
	return x;
}
const int N=55;
int a[N][N];
int b[N][N];
bool va[N][N][N][N];
bool vb[N][N][N][N];
void gkd(int a[N][N],bool f[N][N][N][N]){
	rep(i,1,n)rep(j,1,n)f[i][j][i][j]=1;
	rep(i,1,n)rep(j,1,n){
		if(i+1<=n)f[i][j][i+1][j]=(a[i][j]==a[i+1][j]);
		if(j+1<=n)f[i][j][i][j+1]=(a[i][j]==a[i][j+1]);
	}
	rep(dis,2,2*n-2)rep(x1,1,n)rep(y1,1,n)rep(dx,0,min(n-x1,dis)){
		int dy=dis-dx;
		int x2=x1+dx;
		int y2=y1+dy;
		if(!(y1<=y2&&y2<=n))continue;
		if(a[x1][y1]!=a[x2][y2])f[x1][y1][x2][y2]=0;
		else{
			f[x1][y1][x2][y2]=f[x1+1][y1][x2-1][y2]|f[x1+1][y1][x2][y2-1]|f[x1][y1+1][x2-1][y2]|f[x1][y1+1][x2][y2-1];
		}
	}
}
int main(){
	scanf("%d",&n);
	a[1][1]=1;
	a[n][n]=0;
	rep(i,1,n)rep(j,1,n)if(i+j>2)if(i+j!=2*n)if((i+j)%2==0){
		if(i>1&&j>1){
			a[i][j]=a[i-1][j-1]^(!ask(i-1,j-1,i,j));
		}
		else
		if(i>2){
			a[i][j]=a[i-2][j]^(!ask(i-2,j,i,j));
		}
		else{
			a[i][j]=a[i][j-2]^(!ask(i,j-2,i,j));
		}
	}
	a[1][2]=1;
	a[3][2]=ask(1,2,3,2);
	a[2][1]=(!ask(2,1,3,2))^a[3][2];
	rep(i,1,n)rep(j,1,n)if(i+j!=3)if((i+j)%2==1){
		if(i>1&&j>1){
			a[i][j]=a[i-1][j-1]^(!ask(i-1,j-1,i,j));
		}
		else
		if(i>2){
			a[i][j]=a[i-2][j]^(!ask(i-2,j,i,j));
		}
		else{
			a[i][j]=a[i][j-2]^(!ask(i,j-2,i,j));
		}
	}
	rep(i,1,n)rep(j,1,n){
		b[i][j]=(a[i][j]^(((i+j)%2==1)));
	}
	gkd(a,va);
	gkd(b,vb);
	rep(x1,1,n)rep(y1,1,n)rep(x2,x1,n)rep(y2,y1,n)if(x1+y1+2<=x2+y2){
		if(va[x1][y1][x2][y2]!=vb[x1][y1][x2][y2]){
			if(ask(x1,y1,x2,y2)==va[x1][y1][x2][y2]){
				puts("!");
				rep(i,1,n){
					rep(j,1,n)putchar(a[i][j]+'0');
					puts("");
				}
				fflush(stdout);
			}
			else{
				puts("!");
				rep(i,1,n){
					rep(j,1,n)putchar(b[i][j]+'0');
					puts("");
				}
				fflush(stdout);
			}
			return 0;
		}
	}
	puts("!");
	rep(i,1,n){
		rep(j,1,n)putchar(a[i][j]+'0');
		puts("");
	}
	fflush(stdout);
	return 0;
}