#include <cstdio>
int a[105];
int len;
int n,p;
int check(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;n-p*i>=0;i++){
		if(check(n-p*i)<=i&&n-p*i>=i){
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}