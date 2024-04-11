#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

int n;
int a,b,c,d;

int main()
{
	n=IN();
	For(i,0,4)
	{
		a=IN(),b=IN(),c=IN(),d=IN();
		if (min(a,b)+min(c,d)<=n)
			return printf("%d %d %d\n",i+1,min(a,b),n-min(a,b)),0;
	}
	puts("-1");
}