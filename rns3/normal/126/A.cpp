#include<cstdio>
#include<cmath>
#define R(x,y) return printf("%d %d\n",x,y),0;
double w=1e90,x;
int a,b,p,q,t,h,s,i,j;
int main(){
	scanf("%d%d%d%d%d",&a,&b,&p,&q,&t);
	a=t-a;b-=t;s=q;
	if(!(a&&b))R(a?0:p,b?0:q);
	for(i=p;~i;--i){
		j=ceil(1.0l*i*a/b-1e-9);
		if(j>q||j<0)continue;
		x=1.0l*(b*j-a*i)/(i+j);
		if(x+1e-9<w)w=x,h=i,s=j;
	}
	R(h,s);
}