#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=305;
int n,a[N],x,k;

int get(int n)
{
	int ret;
	rep(i,1,n) putchar('a'+a[i]);
	puts(""),fflush(stdout);
	scanf("%d",&ret);
	return ret;
}

int main()
{
	x=get(1);
	rep(i,1,x) a[i]=1;
	k=get(x);
	if(!k) return 0;
	a[n=x+1]=1;
	rep(i,1,n-1)
	{
		a[i]=0,x=get(n);
		if(x<k) k=x; else a[i]=1;
	}
	if(x) a[n]^=1;
	get(n);
	return 0;
}