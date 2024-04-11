#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

int a,b,n,x,y,f;

int main()
{
	n=IN();
	For(i,0,n) x=IN()&1,y=IN()&1,a^=x,b^=y,f|=x^y;
	printf("%d\n",a^b?-1:a?f?1:-1:0);
}