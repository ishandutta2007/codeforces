#include <cstdio>
int main(){
	int h,l;
	scanf("%d%d",&h,&l);
	double ans=((double)l*l-(double)h*h)/(2.0*h);
	printf("%.7lf\n",ans);
	return 0;
}