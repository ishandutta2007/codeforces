#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
const int N=105;
int f[N][N];
int n,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	memset(f,63,sizeof f);
	f[0][0]=0;
	rep(i,0,n-1)rep(j,0,2){
		f[i+1][0]=min(f[i][j]+1,f[i+1][0]);
		if(j!=1&&(a[i+1]&1))f[i+1][1]=min(f[i+1][1],f[i][j]);
		if(j!=2&&(a[i+1]&2))f[i+1][2]=min(f[i+1][2],f[i][j]);
		//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
	}
	int ans=min(f[n][0],min(f[n][1],f[n][2]));
	printf("%d\n",ans);
	return 0;
}