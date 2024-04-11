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

int n,x,c;

int main()
{
	for (n=2*IN(),x=IN();n--;)
	{
		c=IN();
		if (c==x||c==7-x) return puts("NO"),0;
	}
	puts("YES");
}