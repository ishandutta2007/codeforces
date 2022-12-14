#include<cstdio>
const int N=1005;
typedef long long ll;
int n,m,k,a[N][N];
ll s[N][N],f[N][N],g[N][N];
ll calc(int a,int b){
	return (g[a+k-1][b]-g[a-1][b+k]+g[a-1][b-k]-(k==a?0:g[a-k-1][b]))-(f[a-1][b+k-1]-(a==k?0:f[a-k-1][b-1])+f[a+k-1][b-1]-(k==b?0:f[a-1][b-k-1]));
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",a[i]+j);
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
		for(int j=0;j<=m;j++){
			if(j)f[i][j]=f[i-1][j-1]+s[i][j];
			g[i][j]=g[i-1][j+1]+s[i][j];
		}
	}
	ll ans=-1;
	int x,y;
	for(int i=k;i<=n-k+1;i++)
		for(int j=k;j<=m-k+1;j++)
			if(calc(i,j)>ans)
				ans=calc(x=i,y=j);
	printf("%d %d\n",x,y);
	return 0;
}