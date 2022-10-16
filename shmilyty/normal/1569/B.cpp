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
int t,n;
char ans[51][51];
string s;
vector<int> v1,v2;
void solve()
{
	n=read();
	cin>>s;
	v1.clear();
	v2.clear();
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			v1.push_back(i+1);
		else
			v2.push_back(i+1);
	if(v2.size()==1||v2.size()==2)
	{
		puts("NO");
		return ;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			ans[i][l]='=';
	for(int i=1;i<=n;i++)
		ans[i][i]='X';
	int k=v2.size();
	for(int i=0;i<k;i++)
		for(int l=0;l<k;l++)
		{
			if((i+1)%k==l)
				ans[v2[i]][v2[l]]='+';
			if((l+1)%k==i)
				ans[v2[i]][v2[l]]='-';
		}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=n;l++)
			cout<<ans[i][l];
		cout<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}