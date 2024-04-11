#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,lst,llst,now;
long long ans;
struct pt
{int x,y;}p[N];
bool cpx(pt a,pt b)
{return a.x<b.x;}
bool cpy(pt a,pt b)
{return a.y==b.y?a.x<b.x:a.y<b.y;}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d",&p[i].x,&p[i].y);
	sort(p,p+n,cpx);
	lst=p[0].x;
	for(int i=0;i<n;i++)
	{
		if(p[i].x!=lst)
		{ans+=now*(long long)(now-1);lst=p[i].x;now=0;}
		now++;
	}
	ans+=now*(long long)(now-1);
	sort(p,p+n,cpy);
	lst=p[0].y;now=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].y!=lst)
		{ans+=now*(long long)(now-1);lst=p[i].y;now=0;}
		now++;
	}
	ans+=now*(long long)(now-1);
	lst=p[0].x,llst=p[0].y;now=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].x!=lst||p[i].y!=llst)
		{ans-=now*(long long)(now-1);lst=p[i].x,llst=p[i].y;now=0;}
		now++;
	}
	ans-=now*(long long)(now-1);
	printf("%lld",ans/2);
}