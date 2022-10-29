#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
long long n,s,d;
long long ans;

int main()
{
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d%d",&s,&d);
		while(s<=ans) s+=d;
		ans=s;
	}
	printf("%I64d\n",ans);
	return 0;
}