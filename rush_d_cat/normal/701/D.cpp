#include<cstdio>
int main(){
	int n,k;
	double l,v1,v2;
	scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k);
    int g=(n+k-1)/k;
	double a=(v1+v2)*l/(v1*(2*g-1)+v2);
	printf("%.7f\n",a/v2+(l-a)/v1);
}