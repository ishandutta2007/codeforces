#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<queue>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,m,k;
int a[N];
int ans,nw;
priority_queue<int> h;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,2,n) h.push(-a[i]+a[i-1]+1);
	ans=n,nw=n;
	while(nw>k)
	{
		--nw;
		ans-=h.top();
		h.pop();
	}
	printf("%d\n",ans);
	return 0;
}