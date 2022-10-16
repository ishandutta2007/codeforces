#include <cstdio>
#include <map>
using namespace std;
const int N=3e5+5;
const int C=1e6+5;
int n,q;
int a[N],p[C],pf[C],f[N];
bool even[N],pls[C];
int u[N],v[N],ans[N];
map <pair<int,int>,int> mp;
int getf(int u)
{
	if (!f[u])
		return u;
	return f[u]=getf(f[u]);
}
void merge(int a,int b)
{
	//printf("merge %d %d\n",a,b);
	a=getf(a);
	b=getf(b);
	f[b]=a;
	even[a]|=even[b];
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
		if (a[i]&1^1)
			even[i]=1;
	for (int i=2;i<C;i++)
	{
		int cur=p[i];
		for (int j=2*i;j<C;j+=i)
			if (p[j])
				if (cur==0)
					cur=p[j];
				else
					if (getf(cur)!=getf(p[j]))
					{
						//printf("i %d j %d pi %d pj %d\n",i,j,cur,p[j]);
						merge(cur,p[j]);
					}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		int fu=getf(u[i]),fv=getf(v[i]);
		//printf("> %d %d\n",fu,fv);
		if (fu==fv)
		{
			ans[i]=0;
			continue;
		}
		if (even[fu]&&even[fv])
		{
			ans[i]=0;
			continue;
		}
		if ((even[fu]&&!even[fv])||(even[fv]&&!even[fu]))
		{
			ans[i]=1;
			continue;
		}
		if ((!even[fu])&&(!even[fv]))
		{
			ans[i]=2;
			mp[{fu,fv}]=1;
			mp[{fv,fu}]=1;
			continue;
		}
	}
	for (int i=2;i<C;i++)
	{
		int cur=p[i];
		for (int j=2*i;j<C;j+=i)
			if (p[j])
			{
				cur=p[j];
				break;
			}
		if (!cur)
			continue;
		pf[i]=getf(cur);
	}
	for (int i=2;i<C;i++)
		if (pf[i])
			for (int j=2*i;j<C;j+=i)
				if (p[j-1])
					if (mp[{pf[i],getf(p[j-1])}])
						mp[{pf[i],getf(p[j-1])}]=2;
	for (int i=2;i<C;i++)
		for (int j=i;j<C;j+=i)
			if (p[j-1])
				pls[i]=1;
	for (int i=2;i<C;i++)
		if (pf[i])
		{
			int cur=(C-1)/i;
			for (int j=i;j<=cur;j++)
				if (pf[j])
					if (pls[i*j])
						if (mp[{pf[i],pf[j]}])
							mp[{pf[i],pf[j]}]=2;
		}
	for (int i=1;i<=q;i++)
	{
		int fu=getf(u[i]),fv=getf(v[i]);
		if ((!even[fu])&&(!even[fv]))
		{
			if (mp[{fu,fv}]==2)
				ans[i]=1;
			if (mp[{fv,fu}]==2)
				ans[i]=1;
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}