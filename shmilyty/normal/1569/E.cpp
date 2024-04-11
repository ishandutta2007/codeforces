#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
const int mod=998244353;
int n,k,A,hsh,pw[233],a[]={1,2,3,5,9,17};
map<int,vector<int> > mp[2];
signed main()
{
	k=read();
	n=(1<<k);
	A=read();
	hsh=read();
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*A%mod;
	for(int i=0;i<(1<<(n/2));i++)
	{
		int h=0;
		vector<int> A;
		for(int l=1;l*2<=n;l++)
		{
			int g=l+n/2-1,t=k;
			while(g)
			{
				if((i>>(g/2)&1)^(g&1))
					break;
				t--;
				g>>=1;
			}
			(h+=l*pw[a[t]]%mod)%=mod;
			A.push_back(a[t]);
		}
		mp[i&1][h]=A;
	}
	for(int i=0;i<(1<<(n/2));i++)
	{
		int h=0;
		vector<int> A;
		for(int l=1;l*2<=n;l++)
		{
			int g=l+n/2-1,t=k;
			while(g)
			{
				if((i>>(g/2)&1)^(g&1))
					break;
				t--;
				g>>=1;
			}
			(h+=(l+n/2)*pw[a[t]]%mod)%=mod;
			A.push_back(a[t]);
		}
		h=(hsh+mod-h)%mod;
		if(mp[(i&1)^1].count(h))
		{
			for(int l:mp[(i&1)^1][h])
				cout<<l<<" ";
			for(int l:A)
				cout<<l<<" ";
			return 0;
		} 
	}
	puts("-1");
	return 0;
}