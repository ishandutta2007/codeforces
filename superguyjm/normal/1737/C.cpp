#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;
int n,a[10],b[10],x,y,_x,_y;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(int x,int y)
{
	int cx=0,cy=0;
	rep(i,0,2) 
	{
		if(x==a[i]) ++cx;
		if(y==b[i]) ++cy;
	}
	return cx==2 && cy==2;
}

void solve()
{
	n=getint();
	rep(i,0,2) a[i]=getint(),b[i]=getint();
	x=getint(),y=getint();
	rep(i,0,2) if(check(a[i],b[i]))
	{
		_x=a[i],_y=b[i];
		break;
	}
	if((_x==1 || _x==n) && (_y==1 || _y==n))
	{
		if(_x==n) x=n-x+1;
		if(_y==n) y=n-y+1;
		if(x==1 || y==1) puts("YES");
		else puts("NO");
		return;
	}
	if((x&1)==(_x&1) || (y&1)==(_y&1)) puts("YES");
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}