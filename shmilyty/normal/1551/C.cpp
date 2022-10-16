#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,ans,a[200001][5],len[200001];
vector<int> v;
void solve()
{
	n=read();
	ans=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		len[i]=s.size();
		for(int l=0;l<5;l++)
			a[i][l]=0;
		for(int l=0;l<s.size();l++)	
			a[i][s[l]-'a']++;
	}
	for(int i=0;i<5;i++)
	{
		v.clear();
		for(int l=1;l<=n;l++)
			v.push_back(2*a[l][i]-len[l]);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		int tot=0;
		for(int l=0;l<n;l++)
		{
			tot+=v[l];
			if(tot<=0)
			{
				ans=max(ans,l);
				break;
			} 
		}
		if(tot>0)
		{
			ans=n;
			break;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}