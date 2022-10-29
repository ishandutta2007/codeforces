#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int n,m,vis,x,ans,a[10000];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,m)
	{
		x=getint();
		++a[x],vis=0;
		rep(j,1,n) if(!a[j]) {vis=1; break;}
		if(!vis)
		{
			++ans;
			rep(j,1,n) --a[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}