#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,ans;

int main()
{
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	while(n*2>m&&n>=3)n-=3,m-=3,ans+=2;
	ans+=min(n,m/2);
	printf("%d",ans);
}