#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int a,b,c;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	printf("%lld\n",2ll*c+2ll*min(a,b)+(a!=b));
	return 0;
}