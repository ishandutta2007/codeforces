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

int ax,ay,bx,by;

int main()
{
	scanf("%d:%d%d:%d",&ax,&ay,&bx,&by);
	ax-=bx,ay-=by;
	if (ay<0) ax--,ay+=60;
	if (ax<0) ax+=24;
	printf("%02d:%02d\n",ax,ay);
}