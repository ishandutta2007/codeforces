#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans,area;
int n,fx=31400,fy=31400,gx=0,gy=0,nx,ny,px,py;
int main(){
scanf("%d",&n);
while(n--)
{
scanf("%d%d%d%d",&nx,&ny,&px,&py);
fx=min(fx,nx),fy=min(fy,ny);
gx=max(px,gx),gy=max(py,gy);
ans+=(ll)(px-nx)*(py-ny);
}
if(gx-fx==gy-fy&&ans==(ll)(gx-fx)*(gy-fy)) printf("YES\n");
else printf("NO\n");
return 0;
}