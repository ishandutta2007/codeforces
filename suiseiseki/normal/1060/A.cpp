#include <cstdio>
char s[105];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int eight=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='8'){
			eight++;
		}
	}
	printf("%d\n",mn(eight,n/11));
	return 0;
}