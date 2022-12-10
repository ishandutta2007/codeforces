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

int x;

int main()
{
	scanf("%d",&x);
	if (x>=0) return printf("%d\n",x),0;
	x=-x;
	if (min(x/10,(x/100*10+x%10))) putchar('-');
	printf("%d\n",min(x/10,(x/100*10+x%10)));
}