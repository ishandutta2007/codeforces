#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int t,n,a[100];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		rep(i,1,n) a[i]=n-i+1;
		rep(i,1,n)
		{
			rep(j,1,n) printf("%d ",a[j]);
			puts("");
			swap(a[n-i+1],a[n-i]);
		}
	}		
	return 0;
}