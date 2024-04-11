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
const int mod=1e9+7;
int t,m,f[10][200001];
string s;
void solve()
{
	cin>>s;
	m=read();
	int ans=0;
	for(int i=0;i<s.size();i++)
		(ans+=f[s[i]-'0'][m])%=mod;
	cout<<ans<<endl;
} 
signed main()
{
	for(int i=0;i<=200000;i++)
		for(int l=0;l<=9;l++)
		{
			if(l+i<=9)
				f[l][i]=1;
			else
				f[l][i]=(f[1][i+l-10]+f[0][i+l-10])%mod;
		}
	t=read();
	while(t--)
		solve(); 
	return 0;
}