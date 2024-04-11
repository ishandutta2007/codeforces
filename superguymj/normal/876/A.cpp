#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,a,b,c,x,ans;

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(n==1) return puts("0"),0;
	if(n==2) return printf("%d\n",min(a,b)),0;
	x=min(a,min(b,c));
	if(x==a) ans=a*(n-1);
	else if(x==b) ans=b*(n-1);
	else ans=min(a,b)+c*(n-2);
	printf("%d\n",ans);
	return 0;
}