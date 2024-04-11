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
int T,n,k,num[26];
char s[201];
std::vector<char> v;
void solve()
{
	n=read();
	k=read();
	scanf("%s",s+1);
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
		num[s[i]-'a']++;
	for(int i=1;i<=k;i++)
	{
		bool ok=1;
		for(char l='a';l<='y';l++)
		{
			if(!num[l-'a'])
			{
				cout<<l;
				ok=0;
				break;
			}
			if(l-'a'==n/k)
			{
				cout<<l;
				ok=0;
				break;
			}
			num[l-'a']--;
		}
		if(ok)
			cout<<'z';
	}
	v.clear();
	cout<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}