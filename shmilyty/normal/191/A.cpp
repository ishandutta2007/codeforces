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
int n,f[26][26];
string s[500001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int len=s[i].size();
		for(int l=0;l<26;l++)
			if(f[l][s[i][0]-'a'])
				f[l][s[i].back()-'a']=max(f[l][s[i].back()-'a'],f[l][s[i][0]-'a']+len);
		f[s[i][0]-'a'][s[i].back()-'a']=max(f[s[i][0]-'a'][s[i].back()-'a'],len); 
	}
	int ans=0;
	for(int i=0;i<26;i++)
		ans=max(ans,f[i][i]);
	cout<<ans;	
	return 0;
}