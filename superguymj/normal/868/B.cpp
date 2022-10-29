#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int h,m,s,t1,t2;
bool vis1,vis2;

int main()
{
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	if(t1>t2) swap(t1,t2);
	if(m || s)
	{
		if(h>=t1 && h<t2) vis1=1;
		if(h<t1 || h>=t2) vis2=1;
	}
	else
	{
		if(h>t1 && h<t2) vis1=1;
		if(h<t1 || h>t2) vis2=1;
	}
	t1=t1*5%60,t2=t2*5%60;
	if(t1>t2) swap(t1,t2),swap(vis1,vis2);
	if(s>t1 && s<t2) vis1=1;
	if(s<t1 || s>t2) vis2=1;
	if(s)
	{
		if(m>=t1 && m<t2) vis1=1;
		if(m<t1 || m>=t2) vis2=1;
	}
	else
	{
		if(m>t1 && m<t2) vis1=1;
		if(m<t1 || m>t2) vis2=1;
	}
	if(vis1 && vis2) puts("NO");
	else puts("YES");
	return 0;
}