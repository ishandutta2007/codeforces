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

int x,y,a,b,tot;

int main()
{
	x=IN(),y=IN(),a=IN(),b=IN();
	for (int i=a;i<=x;i++)
		for (int j=b;j<=y;j++) if (i>j) tot++;
	printf("%d\n",tot);
	for (int i=a;i<=x;i++)
		for (int j=b;j<=y;j++) if (i>j) printf("%d %d\n",i,j);	
}