#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
int n;LL x;
char c[50+19];

int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for (int i=strlen(c)-1;i>=0;i--) x=(x<<1)+(c[i]=='R');
	printf("%I64d\n",(1LL<<n)-1-x);
}