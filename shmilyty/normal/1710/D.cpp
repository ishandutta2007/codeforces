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
int T,n,nxt[2001];
char s[2001][2001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]);
	for(int i=1;i<=n;i++)
		nxt[i]=i;
	for(int l=n;l;l--)
		for(int r=l;r<=n;r++)
			if(s[l][r-l]=='1'&&nxt[l]<r)
			{
				cout<<l<<' '<<r<<'\n';
				if(nxt[nxt[l]+1]+1<r)
				{
					cout<<nxt[l]+1<<" "<<r<<'\n';
					for(int i=nxt[nxt[l]+1]+1;i<r;i++)
						if(nxt[i]==i)
							cout<<l<<" "<<i<<'\n';
				}
				for(int i=l;i<=r;i++)
					nxt[i]=nxt[r];
			}
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}