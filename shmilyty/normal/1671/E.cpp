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
const int N=3e5,bse=17,mod=998244353,m1=1e9+7;
int n,f[N],a[N],lev[N];
vector<bool> v[N];
char s[N];
signed main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=(1<<n)-1;i;i--)
		if(i*2>=(1<<n))
		{
			f[i]=1;
			a[i]=s[i]-'A';
			v[i].push_back(s[i]-'A');
		}
		else
		{
			f[i]=f[i<<1]*f[i<<1|1]%mod;
			bool ok=1;
			for(int l=0;l<v[i<<1].size();l++)
				if(v[i<<1][l]!=v[i<<1|1][l])
				{
					ok=0;
					break;
				}
			if(!ok)
				(f[i]*=2)%=mod;
			v[i].push_back(s[i]-'A');
			if(v[i<<1]<v[i<<1|1])
				swap(v[i<<1],v[i<<1|1]);
			for(int l:v[i<<1])
				v[i].push_back(l);
			for(int l:v[i<<1|1])
				v[i].push_back(l);
		}
	cout<<f[1];
	return 0;
}