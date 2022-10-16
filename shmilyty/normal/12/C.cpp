#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int n,m,a[101];
vector<int> v;
map<string,int> mp;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)
	{
		string s;
		cin>>s;
		mp[s]++;
	}
	for(auto it:mp)
		v.push_back(it.second);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<v.size();i++)
		ans+=v[i]*a[i+1];
	cout<<ans<<endl;
	ans=0;
	reverse(a+1,a+1+n);
	for(int i=0;i<v.size();i++)
		ans+=v[i]*a[i+1];
	cout<<ans;
	return 0;
}