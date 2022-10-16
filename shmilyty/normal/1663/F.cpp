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
string s,a[]={"","","","the","","buffy","slayer","vampire"};
int n,b[1000];
signed main()
{
	cin>>s;
	n=s.size();
	if(n==4)
	{
		puts("none");
		return 0;
	}
	for(int i=0;i<n;i++)
		b[i]=(s[i]+a[n][i]-'a'-'a')%26;
	for(int i=0;i<n;i++)
		cout<<(char)('a'+b[i]);
	return 0;
}