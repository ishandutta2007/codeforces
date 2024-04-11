#include<cstdio>
using namespace std;

int n,x;
char s[19];

int main()
{
	scanf("%d",&n);
	while (n--) scanf("%s",s),x+=(s[1]=='+'?1:-1);
	printf("%d\n",x);
}