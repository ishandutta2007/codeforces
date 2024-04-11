#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
int n,q,rb[200001],ok[200001];
set<int> s;
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n+1;i++)
		s.insert(i);
	fill(rb+1,rb+1+n,INF);
	while(q--)
	{
		int opt=read();
		if(opt)
		{
			int x=read();
			if(s.find(x)==s.end())
				puts("NO");
			elif(ok[x])
				puts("YES");
			else
				puts("N/A");
			continue;
		}
		int x=read(),y=read(),z=read();
		if(z)
		{
			int l=*s.lower_bound(x);
			rb[l]=min(rb[l],y);
			if(rb[l]<*s.upper_bound(l))
				ok[l]=1;
		}
		else
		{
			int r=*s.upper_bound(y);
			for(auto i=s.lower_bound(x);(*i)<=y;)
			{
				if(r!=n+1)
					rb[r]=min(rb[r],rb[*i]);
				int l=*i;
				i++;
				s.erase(l);
			}
			if(r!=n+1&&rb[r]<*s.upper_bound(r))
				ok[r]=1;
			if(*s.begin()<x)
			{
				auto l=s.lower_bound(x);
				l--;
				int k=*l;
				if(rb[k]<*s.upper_bound(k))
					ok[k]=1;
			}
		}
	}
	return 0;
}