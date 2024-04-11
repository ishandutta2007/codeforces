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
int n,q,a[200001][2];
string s;
signed main()
{
	n=read();
	q=read();
	cin>>s;
	int lst=s[0];
	for(int i=1;i<n;i++)
	{
		a[i+1][0]=a[i][0];
		a[i+1][1]=a[i][1];
		if(s[i]==lst)
			a[i+1][s[i]-'0']++;
		lst=s[i];
	}
	while(q--)
	{
		int x=read(),y=read();
		int n0=a[y][0]-a[x][0],n1=a[y][1]-a[x][1];
		cout<<max(n0,n1)+1<<'\n';
	}
	return 0;
}