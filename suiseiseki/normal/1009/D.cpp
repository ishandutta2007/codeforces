#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<n-1){
		puts("Impossible");
		return 0;
	}
	int tot=0;
	for(int i=1;i<=n&&tot<m;i++){
		for(int j=i+1;j<=n&&tot<m;j++){
			if(gcd(i,j)==1){
				tot++;
			}
		}
	}
	if(tot<m){
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	tot=0;
	for(int i=1;i<=n&&tot<m;i++){
		for(int j=i+1;j<=n&&tot<m;j++){
			if(gcd(i,j)==1){
				printf("%d %d\n",i,j);
				tot++;
			}
		}
	}
	return 0;
}