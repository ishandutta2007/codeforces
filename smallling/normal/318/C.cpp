#include<stdio.h>

using namespace std;

long long x,y,m,ans;

int main()
{
	scanf("%I64d%I64d%I64d",&x,&y,&m);
	if(x>=m||y>=m){printf("0");return 0;}
	if(x+y<=x&&x+y<=y){printf("-1");return 0;}
	if(x<0)ans+=(-x)/y,x+=ans*y;
	if(y<0)ans+=(-y)/x,y+=ans*x;
	while(x<m&&y<m)
	{
		if(x<y)x+=y;
		else y+=x;
		ans++;
	}
	printf("%I64d",ans);
}