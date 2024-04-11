#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9,N=3e5+2;
pair<int,int> mx[N];
int fir[N],nxt[N],lst[N];
int n,c,fh,i,ans,anss,t,x,j;
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);
		memset(fir+1,0,n<<2);
		memset(lst+1,0,n<<2);
		memset(nxt+1,0,n<<2);
		for (i=1;i<=n;i++)
		{
			read(x);if (!fir[x]) fir[x]=lst[x]=i; else lst[x]=nxt[lst[x]]=i;
		}
		for (i=1;i<=n+1;i++) mx[mx[i].second=i].first=inf;
		for (i=1;i<=n;i++) if (fir[i])
		{
			mx[i].first=max(fir[i],n-lst[i]+1);
			for (j=fir[i];j!=lst[i];j=nxt[j]) mx[i].first=max(mx[i].first,nxt[j]-j);
		}
		sort(mx+1,mx+n+1);ans=inf;
		for (i=1,j=0;i<=n;i++)
		{
			while ((mx[j+1].first!=inf)&&(i>=mx[j+1].first)) 
			{
				++j;
				ans=min(ans,mx[j].second);
			}
			if (ans==inf) printf("-1 "); else printf("%d ",ans);
		}puts("");
	}
}