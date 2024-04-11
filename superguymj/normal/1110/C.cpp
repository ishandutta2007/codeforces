#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int q,x;

int calc(int x)
{
	int p=sqrt(x);
	rep(i,2,p) if(x%i==0) return x/i;
	return 1;
}

int f(int x)
{
	rep(i,0,25) if(x==(1<<i)-1) return calc(x);
	repd(i,25,0) if(x&(1<<i)) return (1<<i+1)-1;
}

int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		printf("%d\n",f(x));
	}
	return 0;
}