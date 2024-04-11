#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 305
#define inf 1ll<<40
typedef long long ll;

int n,m,k;

ll f[max_N][max_N],cost[max_N][max_N];

int main(){
	n=gint(),m=gint(),k=gint();
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cost[i][j]=inf;
	for(int i=1,l,r,c;i<=m;++i){
		l=gint(),r=gint(),c=gint();
		for(int j=l;j<=r;++j)cost[l][j]=min(cost[l][j],1ll*c);
	}
	for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)f[i][j]=inf;
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		f[i][0]=0;
		for(int j=1;j<=i;++j){
			f[i][j]=f[i-1][j];
			for(int k=1;k<=j;++k){
				f[i][j]=min(f[i][j],f[i-k][j-k]+cost[i-k+1][i]);
			}
		}
	}
	if(f[n][k]==inf)puts("-1");
	else printf("%I64d\n",f[n][k]);
	return 0;
}