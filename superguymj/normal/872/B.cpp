#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)


using namespace std;
int n,k,mx,mn,x,a[100005],minn1[100005],minn2[100005];

int main()
{
	scanf("%d%d",&n,&k);
	mx=-1e9,mn=1e9;
	rep(i,1,n) scanf("%d",&x),a[i]=x,mx=max(mx,x),mn=min(mn,x);
	minn1[0]=minn2[n+1]=1e9;
	rep(i,1,n) minn1[i]=min(minn1[i-1],a[i]);
	repd(i,n,1) minn2[i]=min(minn2[i+1],a[i]);
	if(k==1) printf("%d\n",mn);
	else if(k==2)
	{
		mx=-1e9;
		rep(i,1,n-1) mx=max(mx,max(minn1[i],minn2[i+1]));
		printf("%d\n",mx);
	}
	else printf("%d\n",mx);
	return 0;
}