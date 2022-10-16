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
int t,n,k,x,a[2010],ans[2010],to[2010];
string s;
void solve()
{
	n=read();
	k=read();
	x=read()-1;
	cin>>s;
	s=" "+s;
	int cnt=0;
	int top=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='a'&&cnt)
		{
			a[++top]=cnt*k;
			cnt=0;
		}
		elif(s[i]=='*')
			cnt++;
	if(cnt)
		a[++top]=cnt*k;
	cnt=x;
	for(int i=top,lst;i;i--)
	{
		lst=a[i];
		a[i]=cnt%(lst+1);
		cnt/=(lst+1);
	}
	cnt=0;
	int tp=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='a'&&cnt)
		{
			tp++;
			for(int l=1;l<=a[tp];l++)
				cout<<'b';
			cnt=0;
		}
		if(s[i]=='a')
			cout<<'a';
		else
			cnt++;	
	}
	if(s[n]!='a')
		for(int i=1;i<=a[top];i++)
			cout<<'b';
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}