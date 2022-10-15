#include <cstdio>
int n,u,s,d[200005];
void update(){scanf("%d",&u);s=1ll*s*++d[u]%998244353;}
int main(){scanf("%d",&n);s=n--;for (n*=2;n;n--)update();printf("%d",s);}