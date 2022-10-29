#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1005;
typedef long long LL;
int n,ans[N];
struct point{int x,y;} p[N];

LL sqr(LL x) {return x*x;}

int main()
{
	scanf("%d",&n);
	rep(i,1,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i].x=x+1000000;
		p[i].y=y+1000000;
	}
	rep(i,0,60)
	{
		*ans=0;
		rep(j,1,n) if(!((sqr(p[j].x-p[1].x)+sqr(p[j].y-p[1].y)>>i)&1)) ans[++*ans]=j;
		if(*ans<n) break;
	}
	printf("%d\n",*ans);
	rep(i,1,*ans) printf("%d ",ans[i]);
	puts("");
	return 0;
}