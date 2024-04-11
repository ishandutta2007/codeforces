#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=5000;
int n,m;
char a[Maxn+5],b[Maxn+5];
int f[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				f[i][j]=max(f[i][j],f[i-1][j-1]+2);
			}
			f[i][j]=max(f[i][j],f[i-1][j]-1);
			f[i][j]=max(f[i][j],f[i][j-1]-1);
			ans=max(ans,f[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}