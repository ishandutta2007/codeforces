#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	int  *m;
	int n,k;
	scanf("%d%d",&n,&k);
	m=(int *)calloc(n,sizeof(int));
	int i=0,r=0;
	while(i<n){
		scanf("%d",(m+i));
		i++;
	}
	for(i=1;i<n;++i){
		if(*(m+i)+*(m+i-1)<k){
			r+=k-*(m+i)-*(m+i-1);
			*(m+i)+=k-*(m+i)-*(m+i-1);
		}
	}
	printf("%d\n",r);
	for(i=0;i<n;++i){
		printf("%d ",*(m+i));
	}
	return 0;
}