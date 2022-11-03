#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
int n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	int x=-1,y;
	for(int i=0;i*a<=n;i++){
		if((n-i*a)%b==0){
			x=i;
			y=(n-i*a)/b;
			break;
		}
	}
	if(x==-1){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<a;j++){
			printf("%d ",i*a+(j+1)%a+1);
		}
	}
	for(int i=0;i<y;i++){
		for(int j=0;j<b;j++){
			printf("%d ",i*b+(j+1)%b+1+x*a);
		}
	}
	return 0;
}