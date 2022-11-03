#include <bits/stdc++.h>
 
using namespace std;
 
int n,dn,a[150069],pst[150069],pm[150069],sbt[150069],lz[150069],uv[2069],un=0,sqn=2000,d[150069],pwk,dv=998244353;
vector<int> al[150069],cd[150069];
bitset<150069> vtd;
 
void bd(int x)
{
	int i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	pst[x]=n;
	pm[n]=x;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			cd[x].push_back(pst[l]);
			sbt[x]+=sbt[l];
		}
	}
	sort(cd[x].begin(),cd[x].end());
}
 
int pw(int x,int y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=1ll*pwk*pwk%dv;
	if(y%2==1)
	{
		pwk=1ll*pwk*x%dv;
	}
	return pwk;
}
 
void dfs(int x,int w)
{
	int i,sz=cd[x].size(),l;
	
	w=(w+1ll*lz[x]*(n-sbt[x]))%dv;
	a[x]=(a[x]+w)%dv;
	for(i=0;i<sz;i++)
	{
		l=pm[cd[x][i]];
		dfs(l,(w+dv-1ll*lz[x]*sbt[l]%dv)%dv);
	}
}
 
int main()
{
	int t,rr,i,ky,k,l,z,p,sm=0,w=0;
	
	scanf("%d%d",&n,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	bd(1);
	dn=pw(n,dv-2);
	for(i=1;i<=n;i++)
	{
		for(k=cd[i].size();k;k/=2,d[i]++);
	}
	vtd.reset();
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&ky,&k);
		if(ky==1)
		{
			scanf("%d",&l);
			lz[k]=(lz[k]+1ll*l*dn)%dv;
			sm=(sm+1ll*l*dn%dv*sbt[k])%dv;
			if(!vtd[k])
			{
				un++;
				uv[un]=k;
				vtd[k]=1;
				w+=d[k];
				if(max(un,w)>=sqn)
				{
					dfs(1,sm);
					vtd.reset();
					for(i=1;i<=n;i++)
					{
						lz[i]=0;
					}
					sm=0;
					un=0;
					w=0;
				}
			}
		}
		else if(ky==2)
		{
			z=a[k];
			for(i=1;i<=un;i++)
			{
				if(uv[i]==k)
				{
					z=(z+1ll*lz[uv[i]]*n)%dv;
				}
				else if(pst[k]<pst[uv[i]]||pst[k]>=pst[uv[i]]+sbt[uv[i]])
				{
					z=(z+1ll*lz[uv[i]]*(sbt[uv[i]]))%dv;
				}
				else
				{
					p=pm[cd[uv[i]][upper_bound(cd[uv[i]].begin(),cd[uv[i]].end(),pst[k])-cd[uv[i]].begin()-1]];
					z=(z+1ll*lz[uv[i]]*(n-sbt[p]))%dv;
				}
			}
			printf("%d\n",z);
		}
	}
}