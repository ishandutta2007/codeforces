#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 2005
using namespace std;
typedef long long ll;
typedef long double ld;
int a[N],b[N][N],c[N][N],d[N],e[N],n;
int main(){
	scanf("%d",&n);rep(i,n)scanf("%d",a+i);
	rep(i,n)for(int j=i;j;--j)b[j][i]=b[j+1][i]+(a[j]==1);
	rep(i,n)for(int j=i;j;--j)c[j][i]=c[j+1][i]+(a[j]==2);
	rep(i,n)for(int j=0;j<=i;++j)d[i]=max(d[i],b[1][j]+c[j+1][i]);//,printf("%d %d %d %d\n",b[1][j]+c[j+1][i],j,i);
	for(int i=n;i;--i)for(int j=i;j<=n;++j)e[i]=max(e[i],b[i][j]+c[j+1][n]);
	int ans=0;
	rep(i,n)ans=max(ans,d[i]+e[i+1]);
	printf("%d\n",ans);
	//system("pause");
	return 0;
}