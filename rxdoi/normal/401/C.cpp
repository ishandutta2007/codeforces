#include<cstdio>
using namespace std;

int n,m,x,y,MAX;

int main()
{
	scanf("%d%d",&n,&m);
	MAX=n>m?n:m;
	x=n;y=m/2+(m%2);
	if (y>x+1||n>m+1) {puts("-1");return 0;}
	if (x>y)
		for (int i=0;i<MAX;i++)
		{
			if (n) printf("0"),n--;
			if (m) printf("1"),m--;
			if (n&&n>=m) printf("0"),n--;
			if (m) printf("1"),m--;
		}
	else
		for (int i=0;i<MAX;i++)
		{
			if (m) printf("1"),m--;
			if (m) printf("1"),m--;
			if (n) printf("0"),n--;
		}
}