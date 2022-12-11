#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char c[300+19];
int x,Max,Min;

int main()
{
	scanf("%s",c);
	for (int i=0;i<strlen(c);i++)
	{
		c[i]=='+'?x++:x--;
		Max=max(Max,x),Min=min(Min,x);
	}
	printf("%d\n",Max-Min);
}