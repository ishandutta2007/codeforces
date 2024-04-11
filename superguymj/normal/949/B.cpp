#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back 

using namespace std;
typedef long long LL;
LL n,x,ans;
int q;
bool vis;

void solve(LL l,LL r,LL k)
{
	if(l<=0) {vis=1; return;}
	solve(l-2*k,l-1,k*2);
	if(vis)
	{
		vis=0;
		if(x<l)
		{
			if(x&1) ans=(x+1)/2;
			else x=r-((l-1)/2-x/2);
		}
	}
	else if(!ans)
	{
		LL ql=n-k+1;
		if((x-l+1)&1) ans=(ql+(x-l+2)/2-1);
		else x=(x-l+1)/2+r;
	}
}

int main()
{
	scanf("%lld%d",&n,&q);
	while(q--)
	{
		scanf("%lld",&x),vis=ans=0;
		solve(n*2-1,n*2-1,1);
		printf("%lld\n",ans?ans:n);
	}
	return 0;
}