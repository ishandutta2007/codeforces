#include<cstdio>
using namespace std;

int n,o,x,y,A,sa,B,sb;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d%d",&o,&x,&y);
		if (o==1) A+=x,sa+=x+y;
		else B+=x,sb+=x+y;
	}
	printf("%s\n",A>=sa/2+(sa%2)?"LIVE":"DEAD");
	printf("%s\n",B>=sb/2+(sb%2)?"LIVE":"DEAD");
}