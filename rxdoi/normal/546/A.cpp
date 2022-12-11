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

int k,n,w;

int main()
{
	scanf("%d%d%d",&k,&n,&w);
	printf("%d\n",max((w+1)*w/2*k-n,0));
}