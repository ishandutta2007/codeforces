#include <cstdio>
#define Maxn 1000
char a[Maxn+5];
char b[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int ans=n+1,now,tmp;
	for(int i=1;i<=m-n+1;i++){
		now=0;
		for(int j=1;j<=n;j++){
			if(a[j]!=b[i+j-1]){
				now++;
			}
		}
		if(ans>now){
			ans=now;
			tmp=i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i+tmp-1]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}