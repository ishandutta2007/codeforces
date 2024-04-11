#import <ios>
int v[1<<23],i,n,L=-1U>>9;R(){int p;for(;v[p=L^i]|p>n;L/=2);v[p]=1;i--&&R();printf("%d ",p);}
main(){scanf("%d",&n);printf("%lld ",1LL*n*-~n);i=n;R();}