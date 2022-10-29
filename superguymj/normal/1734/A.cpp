#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=305;
const int INF=1000000000;
int a[N],ans;

int min(int a,int b,int c)
{
	return min(min(a,b),c);
}

int max(int a,int b,int c)
{
	return max(max(a,b),c);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		ans=INF;
		rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n)
			ans=min(ans,max(a[i],a[j],a[k])-min(a[i],a[j],a[k]));
		printf("%d\n",ans);
	}
	return 0;
}