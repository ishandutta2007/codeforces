#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=110;
int n,l,r,a[N];

bool up(int l,int r)
{
	rep(i,l,r-1)
		if(a[i]>=a[i+1]) return 0;
	return 1;
}

bool down(int l,int r)
{
	rep(i,l,r-1)
		if(a[i]<=a[i+1]) return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n-1)
	{
		l=i;
		if(a[i]>=a[i+1]) break;
	}
	if(a[l]>a[l+1])
	{
		if(down(l+1,n)) 
		{puts("YES");return 0;}
	}
	else
	{
		rep(i,l+1,n)
		{
			r=i;
			if(a[i]!=a[i+1]) break;
		}
		if(down(r,n))
		{puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}