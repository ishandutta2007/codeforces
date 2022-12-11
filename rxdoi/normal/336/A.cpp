#include<cstdio>
using namespace std;

int x,y,x1=0,y1,x2,y2=0;

int sgn(int x) {return x>0?1:(x<0?-1:0);}
int abs(int x) {return x>0?x:-x;}

int main()
{
	scanf("%d%d",&x,&y);
	y1=sgn(y)*(abs(x)+abs(y));
	x2=sgn(x)*(abs(x)+abs(y));
	if (x1>x2) 
	{
		int t=x1;x1=x2;x2=t;
		t=y1;y1=y2;y2=t;
	}
	printf("%d %d %d %d\n",x1,y1,x2,y2);
	return 0;
}