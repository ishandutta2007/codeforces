#include<bits/stdc++.h>
using namespace std;

long double h[1005];
int x[1005],n,r;
int main(){
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		h[i]=r;
		for(int j=0;j<i;j++)if(abs(x[j]-x[i])<=2*r){
			long double t=sqrt(4*r*r-(x[j]-x[i])*(x[j]-x[i]))+h[j];
			if(t>h[i])h[i]=t;
		}
		printf("%.9lf ",(double)h[i]);
	}
	printf("\n");
	return 0;
}