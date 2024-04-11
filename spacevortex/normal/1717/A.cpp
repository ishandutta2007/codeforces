#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int M=2e4+50;
int T;
int f[M];
struct Node 
{
	int id,w;
}h[M];
bool cmp(const Node &a,const Node &b)
{
	return a.w<b.w;
}
int main()
{
	int i,nw,ans,id;

	T=rd();
	for(i=1;i<=T;i++)
	{
		h[i].id=i;h[i].w=rd();
	}
	sort(h+1,h+T+1,cmp);
	nw=1;ans=1;
	for(i=1;i<=T;i++)
	{
		id=h[i].id;
	//	printf("%d %d\n",h[i].id,h[i].w);
		while(nw<h[i].w)
		{
			nw++;ans++;
			if((nw&1)==0) ans+=2;
			if(nw%3==0) ans+=2;
		}
		f[id]=ans;
	}
	for(i=1;i<=T;i++)
	{
		printf("%d\n",f[i]);
	}
	return 0;
}