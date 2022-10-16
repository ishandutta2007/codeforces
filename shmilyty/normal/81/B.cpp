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
string s;
signed main()
{
	getline(cin,s);
	int n=s.size();
	int i=0;
	while(i<n&&s[i]<=32)
		i++;
	while(i<n)
	{
		char c=s[i];
		int l;
		if(c==',')
			l=1;
		elif(c=='.')
			l=3;
		else
			l=n;
		while(l&&i<n&&isdigit(c)==isdigit(s[i]))
		{
			putchar(s[i++]);
			l--;
		}
		while(i<n&&s[i]<=32)
			i++;
		if(i<n&&(c==','||s[i]=='.'||(isdigit(c)&&isdigit(s[i]))))
			putchar(' ');
	}
	return 0;
}