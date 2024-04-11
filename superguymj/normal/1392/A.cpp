#include<algorithm>
#include<string>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,T,a[200005];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		bool p=0;
		rep(i,1,n-1) if(a[i]!=a[i+1]) p=1;
		if(p) puts("1");
		else printf("%d\n",n);
	}
	return 0;
}