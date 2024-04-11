#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 1005
double f[MAXN][MAXN];int a[MAXN];int n,m;
int main(){
	scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)rep(j,i+1,n)f[i][j]=(a[i]>a[j]);
	while(m--){
		int x,y;scanf("%d%d",&x,&y);if(x>y){int tmp=x;x=y;y=tmp;}
		rep(i,1,x-1)f[i][x]=f[i][y]=(f[i][x]+f[i][y])/2.;
		rep(i,y+1,n)f[y][i]=f[x][i]=(f[y][i]+f[x][i])/2.;
		rep(i,x+1,y-1){
			double tmp1,tmp2;
			tmp1=(f[x][i]+1-f[i][y])/2.;
			f[i][y]=(f[i][y]+1-f[x][i])/2.;
			f[x][i]=tmp1;
		}
		f[x][y]=0.5;
	}
	double res=0;
	rep(i,1,n)rep(j,i+1,n)res+=f[i][j];printf("%.10lf\n",res);
	return 0;
}