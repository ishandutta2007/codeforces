
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;scanf("%d%d",&n,&k);
	if(n*k>n*(n-1)/2){
		printf("-1");
		return 0;
	}
	printf("%d\n",n*k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			printf("%d ",i);
			printf("%d\n",(i+j-1)%n+1);
		}
	}
	return 0;
}