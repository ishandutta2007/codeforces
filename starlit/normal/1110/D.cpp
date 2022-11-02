#include<bits/stdc++.h>
const int N=1000006;
using namespace std;
int n,m,x,y,a[N],f[3][3],g[3][3];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	memset(f,0xef,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=m;i++){
		memcpy(g,f,sizeof f);
		memset(f,0xef,sizeof f);
		for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		for(int l=0;l<3&&j+k+l<=a[i];l++){
			x=(a[i]-j-k-l)/3;
			f[l][j]=max(f[l][j],g[j][k]+k+x);
		}
	}
	printf("%d",f[0][0]);
}