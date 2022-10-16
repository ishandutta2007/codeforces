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
int b,d,ans,cnt[101];
string s1,s2;
signed main()
{
	b=read();
	d=read();
	cin>>s1>>s2;
	for(int i=0;i<s2.size();i++)
		for(int l=0;l<s1.size();l++)
			if(s2[(i+cnt[i])%s2.size()]==s1[l])
				cnt[i]++;
	for(int i=0;i<b;i++)
		ans+=cnt[ans%s2.size()];
	cout<<ans/s2.size()/d;
	return 0;
}