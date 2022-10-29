#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=500005,M=1000005;
int n,a[N],stk[N],tot,p[M],gl[N],gr[N],ll[N],lr[N];
vector <int> D[M],vt[M];
typedef long long LL;
LL ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void init()
{
	n=1000000;
	rep(i,1,n) for(int j=i; j<=n; j+=i) D[j].pb(i);
}

void solve()
{
	n=getint();
	rep(i,1,n) vt[a[i]=getint()].pb(i);

	tot=0;
	rep(i,1,n)
	{
		while(tot && a[stk[tot]]<a[i]) --tot;
		if(!tot) gl[i]=1;
		else gl[i]=stk[tot]+1;
		stk[++tot]=i;
	}

	tot=0;
	rep(i,1,n)
	{
		while(tot && a[stk[tot]]>=a[i]) --tot;
		if(!tot) ll[i]=1;
		else ll[i]=stk[tot]+1;
		stk[++tot]=i;
	}

	tot=0;
	repd(i,n,1)
	{
		while(tot && a[stk[tot]]<=a[i]) --tot;
		if(!tot) gr[i]=n;
		else gr[i]=stk[tot]-1;
		stk[++tot]=i;
	}

	tot=0;
	repd(i,n,1)
	{
		while(tot && a[stk[tot]]>=a[i]) --tot;
		if(!tot) lr[i]=n;
		else lr[i]=stk[tot]-1;
		stk[++tot]=i;
	}

	ans=0;
	rep(i,1,n)
	{
		int l=gl[i],r=gr[i];
		for(auto d:D[a[i]])
		{
			if(p[d])
			{
				int x=vt[d][p[d]-1];
				int _l=ll[x],_r=lr[x];
				if(_r>=i && l<=x) ans+=(LL)(x-max(l,_l)+1)*(min(r,_r)-i+1);
			}
			if(p[d]<(int)vt[d].size())
			{
				int x=vt[d][p[d]];
				int _l=ll[x],_r=lr[x];
				if(p[d]-1>=0)
				{
					int y=vt[d][p[d]-1];
					_l=max(_l,y+1);
				}
				if(r>=x && _l<=i) ans+=(LL)(i-max(l,_l)+1)*(min(r,_r)-x+1);
			}
		}
		++p[a[i]];
	}
	printf("%lld\n",ans);

	rep(i,1,n) vt[a[i]].clear(),p[a[i]]=0;
}

int main()
{
	init();
	int T=getint();	
	while(T--) solve();
	return 0;
}