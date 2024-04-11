#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,k,m,a[N],b[N],vis[N],p[N],x;

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	rep(i,1,n) scanf("%d",&a[i]),b[i]=a[i],a[i]=a[i]%m;
	rep(i,1,n) ++vis[a[i]];
	x=m;
	rep(i,0,m-1) if(vis[i]>=k) {x=i; break;}
	if(x==m) return puts("No"),0;
	puts("Yes");
	rep(i,1,n)
	{
		if(a[i]==x)
			p[++*p]=b[i];
		if((*p)==k) break;
	}
	rep(i,1,*p-1) printf("%d ",p[i]);
	printf("%d\n",p[*p]);
	return 0;
}