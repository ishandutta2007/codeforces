#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n;

int main()
{
	scanf("%d",&n);
	printf("%d\n",n+(n>>1));
	for(int i=2; i<=n; i+=2) printf("%d ",i);
	for(int i=1; i<=n; i+=2) printf("%d ",i);
	for(int i=2; i<=n; i+=2) printf("%d ",i);
	return 0;
}