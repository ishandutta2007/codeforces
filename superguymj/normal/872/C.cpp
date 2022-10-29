#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)


using namespace std;
int n,x,ans,mod;

int main()
{
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%d",&x);
		ans=x/4,mod=x%4;
		if(mod==0) printf("%d\n",ans);
		else if(mod==1)
		{
			if(ans<2) puts("-1");
			else printf("%d\n",ans-1);
		}
		else if(mod==2)
		{
			if(ans<1) puts("-1");
			else printf("%d\n",ans);
		}
		else if(mod==3)
		{
			if(ans<3) puts("-1");
			else printf("%d\n",ans-1);
		}
	}
	return 0;
}