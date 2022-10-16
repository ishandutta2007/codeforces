#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n,q,f[100001];
string s;
signed main()
{
	n=read();
	q=read();
	cin>>s;
	for(int i=0;i<n;i++)
		f[i+1]=f[i]+(s[i]-'a')+1;
	while(q--)
	{
		int l=read(),r=read();
		cout<<f[r]-f[l-1]<<endl; 
	}
	return 0;
}