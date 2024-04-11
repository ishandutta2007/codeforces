#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int n;
int p[333333],c[333333];
inline long long solve(const vector<long long> &v,int l,int r,int L,int R)
{
	long long maxx=max(v[l]-L,R-v[r]);
	for(int i=l+1;i<=r;i++)maxx=max(maxx,v[i]-v[i-1]);
	return maxx;
}
vector<long long> r,g,b;
long long ans;
int main()
{
	scanf("%d",&n);
	char ch;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&p[i],&ch);
		if(ch=='G')c[i]=0,g.push_back(p[i]);
		else if(ch=='R')c[i]=1,r.push_back(p[i]);
		else c[i]=2,b.push_back(p[i]);
	}
	if(g.size()==0)
	{
		if(r.size())ans+=r[r.size()-1]-r[0];
		if(b.size())ans+=b[b.size()-1]-b[0];
		printf("%lld\n",ans);
	}
	else
	{
		int rs=0,bs=0;
		if(r.size())
		{
			if(r[0]<g[0])
			{
				ans+=g[0]-r[0];
				while(rs<r.size()&&r[rs]<g[0])rs++;
			}
			if(r[r.size()-1]>g[g.size()-1])
			{
				ans+=r[r.size()-1]-g[g.size()-1];
			}
		}
		if(b.size())
		{
			if(b[0]<g[0])
			{
				ans+=g[0]-b[0];
				while(bs<b.size()&&b[bs]<g[0])bs++;
			}
			if(b[b.size()-1]>g[g.size()-1])
			{
				ans+=b[b.size()-1]-g[g.size()-1];
			}
		}
		ans+=(g[g.size()-1]-g[0])*3ll;
		r.push_back(inf),b.push_back(inf);
		for(int i=0;i<g.size()-1;i++)
		{
			long long tmp=0;
			int rr=rs;
			while(r[rr]<g[i+1])rr++;
			if(rr>rs)tmp+=solve(r,rs,rr-1,g[i],g[i+1]);
			else tmp+=g[i+1]-g[i];
			rs=rr;
			rr=bs;
			while(b[rr]<g[i+1])rr++;
			if(rr>bs)tmp+=solve(b,bs,rr-1,g[i],g[i+1]);
			else tmp+=g[i+1]-g[i];
			bs=rr;
			if(tmp>g[i+1]-g[i])ans-=tmp;
			else ans-=(g[i+1]-g[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}