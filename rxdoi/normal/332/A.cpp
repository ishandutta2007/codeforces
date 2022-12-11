#include<cstdio>
#include<cstring>
using namespace std;

int n,Ans;
char c[2000+19];

int main()
{
	scanf("%d%s",&n,c);
	for (int i=n;i<strlen(c);i+=n)
		if (c[i-1]==c[i-2]&&c[i-2]==c[i-3]) Ans++,c[i]=c[i-1];
	printf("%d\n",Ans);
}