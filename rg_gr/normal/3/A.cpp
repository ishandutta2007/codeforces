#include <stdio.h>
inline int max(int a,int b){return a>b?a:b;}
inline int abs(int a){return a>0?a:-a;}
int main()
{
	char a=getchar(),b=getchar(),p=getchar(),a0=getchar(),b0=getchar();
	int x=a-a0,y=b-b0;
	printf("%d\n",max(abs(x),abs(y)));
	while(x&&y)
	{
		if(x<0)x++,putchar('R');
		else x--,putchar('L');
		if(y<0)y++,putchar('U');
		else y--,putchar('D');
		puts("");
	}
	if(y)p=y>0?'D':'U';
	else p=x>0?'L':'R';
	for(int i=0;i<abs(x+y);i++)putchar(p),puts("");
	return 0;
}