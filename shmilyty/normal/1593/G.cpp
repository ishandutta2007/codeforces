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
int t,q,f1[1000001],f2[1000001];
string s;
void solve()
{
	cin>>s;
	q=read();
	for(int i=0;i<s.size();i++)
	{
		f1[i+1]=f1[i];
		f2[i+1]=f2[i];
		if(s[i]=='['||s[i]==']')
		{
			if(i&1)
				f1[i+1]++;
			else
				f2[i+1]++;
		}
	}
	while(q--)
	{
		int x=read()-1,y=read();
//		cout<<f2[y]-f2[x]<<" "<<f1[y]-f1[x]<<endl; 
		cout<<abs((f2[y]-f2[x])-(f1[y]-f1[x]))<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}