#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,h,m,x,y,now,ch[]={0,1,5,1919810,1919810,2,1919810,1919810,8,1919810};
//invaid:3,4,6,7,9 
bool ok(int x,int y)
{
	int xx=ch[y%10]*10+ch[y/10];
	int yy=ch[x%10]*10+ch[x/10];
	if(xx>=1919810||y>=1919810)
		return 0;
	if(xx<h&&yy<m)
		return 1;
	return 0;
}
void solve()
{
	h=read();
	m=read();
	scanf("%lld:%lld",&x,&y);
	now=x*m+y;
	for(int i=now;i<h*m;i++)
	{
		x=i/m;
		y=i%m;
		if(ok(x,y))
		{
			cout<<x/10<<x%10<<":"<<y/10<<y%10<<endl;
			return ;	
		} 
	}
	puts("00:00");
	return ; 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}