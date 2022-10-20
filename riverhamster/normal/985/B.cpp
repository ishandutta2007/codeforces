#include <stdio.h>
int a[2048][2048];
int c[2048];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);
			c[j]+=a[i][j];
		}
	bool flag;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) c[j]-=a[i][j];
		flag=true;
		for(int j=1;j<=m;j++){
			// printf("%d ",c[j]);
			if(c[j]==0){
				flag=false;
				break;
			}
		}
		if(flag){
			puts("YES"); return 0;
		}
		for(int j=1;j<=m;j++) c[j]+=a[i][j];
	}
	puts("NO");
	return 0;
}