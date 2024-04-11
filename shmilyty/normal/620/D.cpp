#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
inline int read()
{
	int x=0;
	bool flag=1;
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
struct node{
	int val;
	pair<int,int> p[2];
} ans;
int n,m,s1,s2,x[2001],y[2001],a[2001],b[2001];
pair<int,int> vv1[2001],vv2[2001];
map<int,pair<int,int> > mp;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		s1+=x[i];
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		y[i]=read();
		s2+=y[i];
	}
	if(s1==s2)
	{
		cout<<"0\n0";
		return 0;
	}
	int d=s1-s2;
	ans.val=abs(d);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			s1+=y[l]-x[i];
			s2+=x[i]-y[l];
			if(abs(s1-s2)<ans.val)
			{
				ans.val=abs(s1-s2);
				ans.p[0]={i,l};
			}
			s1-=y[l]-x[i];
			s2-=x[i]-y[l];
		}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			mp[2*(x[i]+x[l])]={i,l};
	for(int i=1;i<=m;i++)
		for(int l=i+1;l<=m;l++)
		{
			int v=d+2*(y[i]+y[l]);
			auto it=mp.lower_bound(v);
			if(it!=mp.begin())
				it--;
			for(int j=1;j<=2&&it!=mp.end();j++,it++)
			{
				int cur=abs(v-it->first);
				if(ans.val>cur)
				{
					ans.val=cur;
					ans.p[0]={it->second.first,i};
					ans.p[1]={it->second.second,l};
				}
			}
		}
	cout<<ans.val<<endl;
	if(ans.p[1].first)
		puts("2");
	else
		if(ans.p[0].first)
			puts("1");
		else
			puts("0");
	for(int i=0;i<2&&ans.p[i].first;i++)
		cout<<ans.p[i].first<<" "<<ans.p[i].second<<endl; 
	return 0;
}