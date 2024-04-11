#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,t,x[3],y[3],o;
char ch;

char getnext()
{
	char ch=getchar();
	while(ch=='\n'||ch==' ')ch=getchar();
	return ch;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		o=0;
		for(i=1;i<=8;i++)
		{
			for(j=1;j<=8;j++)
			{
				ch=getnext();
				if(ch=='K')
				{
					x[++o]=i;
					y[o]=j;
				}
			}
		}
		if(abs(x[1]-x[2])%4==0&&abs(y[1]-y[2])%4==0)printf("YES\n");
		else printf("NO\n");
	}
}