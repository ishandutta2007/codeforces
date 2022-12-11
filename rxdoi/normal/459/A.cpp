#include<cstdio>
#include<cmath>
using namespace std;

int x_1,y_1,x_2,y_2,Len;

int main()
{
	scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
	int xx=abs(x_1-x_2),yy=abs(y_1-y_2);
	if (xx&&yy&&xx!=yy) {printf("-1\n");return 0;}
	Len=(x_1==x_2?abs(y_1-y_2):abs(x_1-x_2));
	if (x_1==x_2) printf("%d %d %d %d\n",x_1+Len,y_1,x_1+Len,y_2);
		else if (y_1==y_2) printf("%d %d %d %d\n",x_1,y_1+Len,x_2,y_1+Len);
			else printf("%d %d %d %d\n",x_1,y_2,x_2,y_1);
}