#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int W,H,x1,y1,x2,y2,w,h;
int solve()
{
	scanf("%d%d",&W,&H);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d",&w,&h);
	if (w+x2-x1>W&&h+y2-y1>H)
		return -1;
	int dis=max(W,H);
	if (w+x2-x1<=W)
	{
		dis=min(dis,max(0,w-x1));
		dis=min(dis,max(0,x2+w-W));
	}
	if (h+y2-y1<=H)
	{
		dis=min(dis,max(0,h-y1));
		dis=min(dis,max(0,y2+h-H));
	}
	return dis;
}
int main()
{
	scanf("%d",&t);
	while (t--)
		printf("%d\n",solve());
	return 0;
}