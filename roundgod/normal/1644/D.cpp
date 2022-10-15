#include<bits/stdc++.h>
#define MAXN 200005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,q;
int r[MAXN],c[MAXN],x[MAXN],y[MAXN];
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&q);
		for(int i=1;i<=n;i++) r[i]=0;
		for(int i=1;i<=m;i++) c[i]=0;
		set<int> rs,cs;
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			r[x[i]]=c[y[i]]=i;
			rs.insert(x[i]); cs.insert(y[i]);
		}

		int minr=0,minc=0;
		if(rs.size()==n)
		{
			minr=INF;
			for(int i=1;i<=n;i++) minr=min(minr,r[i]);
		}
		if(cs.size()==m)
		{
			minc=INF;
			for(int i=1;i<=m;i++) minc=min(minc,c[i]);
		}
		set<int> s;
		for(auto x:rs)
			if(r[x]>=minc) s.insert(r[x]);
		for(auto x:cs)
			if(c[x]>=minr) s.insert(c[x]);
		for(int i=1;i<=q;i++) r[x[i]]=c[y[i]]=0;
		printf("%d\n",pow_mod(k,(int)s.size()));
	}
	return 0;
}