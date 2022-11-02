#include<cstdio>
#include<algorithm>

using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4;

int main()
{
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1==x2)
	{
		printf("%d %d %d %d",x1+abs(y2-y1),y1,x2+abs(y2-y1),y2);
		return 0;
	}
	if(y1==y2)
	{
		printf("%d %d %d %d",x1,y1+abs(x1-x2),x2,y2+abs(x1-x2));
		return 0;
	}
	x3=x2;
	y3=y1;
	x4=x1;
	y4=y2;
	if(abs(y1-y4)==abs(x4-x2))
	{
		printf("%d %d %d %d",x3,y3,x4,y4);
		return 0;
	}
	puts("-1");
}