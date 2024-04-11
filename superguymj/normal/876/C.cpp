#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,p[10000];

int check(int x)
{
	int rt=x;
	while(x) rt+=x%10,x/=10;
	return rt;
}

int main()
{
	scanf("%d",&n);
	rep(i,max(1,n-1000),n)
		if(check(i)==n)
			p[++*p]=i;
	printf("%d\n",*p);
	if(*p)
	{
		rep(i,1,(*p)-1) printf("%d ",p[i]);
		printf("%d\n",p[*p]);
	}
	return 0;
}