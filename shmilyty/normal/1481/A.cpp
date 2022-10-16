#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int t,x,y,xnum,ynum,x1num,y1num; 
string s;
signed main()
{
	t=read();
	while(t--)
	{
		x=read();
		y=read();
		xnum=ynum=x1num=y1num=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='U')
				ynum++; 
			if(s[i]=='R')
				xnum++;
			if(s[i]=='D')
				y1num++;
			if(s[i]=='L')
				x1num++; 
		}
		int ok=0;
		if(x==0)
			ok++;
		if(x>0&&x<=xnum)
			ok++;
		if(x<0&&-x<=x1num)
			ok++;
		if(y==0)
			ok++;
		if(y>0&&y<=ynum)
			ok++;
		if(y<0&&-y<=y1num)
			ok++;
		if(ok==2)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}