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
int n,m,ans,f1[200001],f2[200001];
string s,t;
signed main()
{
	n=read();
	m=read();
	cin>>s>>t;
	int cnt=0;
	for(int i=0;i<n;i++)
		if(s[i]==t[cnt])
		{
			f1[cnt]=i;
			cnt++;
			if(cnt==m-1)
				break;
		}
	cnt=m-1;
	for(int i=n-1;i>=0;i--)
		if(s[i]==t[cnt])
		{
			f2[cnt]=i;
			cnt--;
			if(cnt==0)
				break;
		}
	for(int i=1;i<m;i++)
		ans=max(ans,f2[i]-f1[i-1]);
	cout<<ans;
	return 0;
}