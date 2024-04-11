#include <cstdio>
int c[1005];
int a[1005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	int i=1,j=1;
	while(i<=n&&j<=m){
		while(i<=n&&c[i]>a[j]){
			i++;
		}
		if(i>n){
			break;
		}
		i++;
		j++;
	}
	printf("%d\n",j-1);
	return 0;
}