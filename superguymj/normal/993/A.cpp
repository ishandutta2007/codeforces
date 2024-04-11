#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int INF=10000,o=100;
int vis[1000][1000];
int x,y,mnx,mny,mxx,mxy;

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
	mnx=INF,mny=INF;
	mxx=-INF,mxy=-INF;

	rep(i,0,3)
	{
		mnx=min(mnx,x=getint());
		mny=min(mny,y=getint());
		mxx=max(mxx,x),mxy=max(mxy,y);
	}
	rep(i,mnx,mxx)
		rep(j,mny,mxy)
			vis[i+o][j+o]=1;
	
	
	mnx=INF,mny=INF;
	mxx=-INF,mxy=-INF;

	rep(i,0,3)
	{
		mnx=min(mnx,x=getint());
		mny=min(mny,y=getint());
		mxx=max(mxx,x),mxy=max(mxy,y);
	}
	int p=1,l=(mnx+mxx)/2,r=l;
	rep(i,mny,mxy)
	{
		rep(j,l,r) ++vis[j+o][i+o];
		if(i==(mny+mxy)/2) p=-1;
		l-=p,r+=p;
	}
	rep(i,-100,100)
		rep(j,-100,100)
			if(vis[i+o][j+o]==2)
			{
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}