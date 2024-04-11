/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int n;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();
	int MIN=inf,wh;
	for (int i=1;i<=n;i++)
	{
		int now=max(i,2*(n-i)-1);
		if (now<MIN) MIN=now,wh=i;
	}
	// cout<<wh<<endl;
	vector <pair<int,int> > ans;
	for (int i=1;i<=n-wh;i++) ans.emplace_back(i,n-wh-i+1);
	int re=max(wh,2*(n-wh)-1)-(n-wh),x=wh,y=wh-re+1;
	if (x-y==n-wh-1)
	{
		for (int i=1;i<re;i++) ans.emplace_back(wh-i,wh-re+i);
		ans.emplace_back(wh,wh);
	}
	else
	{
		for (int i=1;i<=re;i++) ans.emplace_back(wh-i+1,wh-re+i);
	}
	
	printf("%d\n",len(ans));
	for (auto [x,y]:ans) printf("%d %d\n",x,y);
}