#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=200+19;
int A[Maxn],cnt=0,n,x;
char c[Maxn];

inline int Abs(int a) {return a>0?a:-a;}

int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for (int i=0;i<strlen(c);i++) cnt+=(c[i]=='x');
	printf("%d\n",Abs(x=n/2-cnt));
	if (x==0) {printf("%s\n",c);return 0;}
	if (x>0)
	{
		for (int i=0;i<strlen(c);i++) 
			if (x>0) 
			{
				printf("x");
				if (c[i]=='X') x--;
			} else printf("%c",c[i]);
		return 0;
	}
	if (x<0)
	{
		for (int i=0;i<strlen(c);i++)
			if (x<0)
			{
				printf("X");
				if (c[i]=='x') x++;
			} else printf("%c",c[i]);
		return 0;
	}
}