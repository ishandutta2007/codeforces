#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=200005;
int n,k,a[N],ans,d[N],x;

int check(int x)
{
	rep(i,1,n) d[i]=abs(x-a[i]);
	sort(d+1,d+1+n);
	return d[k+1];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k),++k;
		rep(i,1,n) scanf("%d",&a[i]);
		ans=1000000000;
		rep(i,1,n-k+1)
		{
			int l=a[i],r=a[i+k-1];
			int dis=max(mid-l,r-mid);
			if(dis<ans) ans=dis,x=mid;
		}
		printf("%d\n",x);
	}
	return 0;
}