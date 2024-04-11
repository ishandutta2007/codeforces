#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int T,p,f,cnts,cntw,s,w,ans;
typedef long long LL;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&p,&f);
		scanf("%d%d",&cnts,&cntw);
		scanf("%d%d",&s,&w);
		if(s>w) swap(s,w),swap(cnts,cntw);
		ans=0;
		rep(i,0,cnts) if((LL)i*s<=p)
		{
			int x=i,y=(p-i*s)/w;
			int _x=min(f/s,cnts-x);
			int _y=min((f-s*_x)/w,cntw-y);
			ans=max(ans,x+y+_x+_y);
		}
		printf("%d\n",ans);
	}
	return 0;
}