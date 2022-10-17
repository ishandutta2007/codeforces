#include <cstdio>
char a[1000005];
char b[1000005];
int main(){
	int n,m;
	n=m=0;
	scanf("%s",a+1);
	scanf("%s",b+1);
	while(a[++n]!='\0');
	while(b[++m]!='\0');
	n--,m--;
	int p=0,k=0;
	for(int i=1;i<=m;i++){
		if(a[i]==b[i]){
			k++;
			continue;
		}
		break;
	}
	for(int i=m;i>0;i--){
		if(a[i+1]==b[i]){
			p++;
			continue;
		}
		break;
	}
	if(k+p<m){
		puts("0");
	}
	else{
		printf("%d\n",(k-(n-p)+2));
		for(int i=(n-p);i<=k;i++){
			printf("%d ",i);
		}
		printf("%d\n",k+1);
	}
	return 0;
}