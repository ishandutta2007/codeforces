#include<stdio.h>
#include<algorithm>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a<b){
		printf("-1\n");
		return 0;
	}
	double ans=(a+b)*1./((a+b)/(2*b));
	if(a-b>=2*b){
		ans=std::min(ans,(a-b)*1./((a-b)/(2*b)));
	}
	printf("%.10f\n",(double)(ans/2));
	return 0;
}