#include<cstdio>
main(){int n,d,u,v,k,m;scanf("%d%d%d%d%d",&n,&d,&u,&v,&k);m=(n-1)/k*2+1;printf("%lf",(1.0*m*v+u)/(1.0*m*u+v)*d/v);}