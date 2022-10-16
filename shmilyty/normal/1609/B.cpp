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
int n,q,ans;
string s;
signed main()
{
	n=read();
	q=read();
	cin>>s;
	for(int i=1;i<n-1;i++)
		if(s[i-1]=='a'&&s[i]=='b'&&s[i+1]=='c')
			ans++;
	while(q--)
	{
		int x=read();
		for(int i=max(1ll,x-2);i<min(n-1,x+3);i++)
			if(s[i-1]=='a'&&s[i]=='b'&&s[i+1]=='c')
				ans--;
		char c;
		cin>>c;
		s[x-1]=c;
		for(int i=max(1ll,x-2);i<min(n-1,x+3);i++)
			if(s[i-1]=='a'&&s[i]=='b'&&s[i+1]=='c')
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}