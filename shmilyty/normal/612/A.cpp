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
int n,p,q;
vector<string> ans;
string s; 
signed main()
{
	n=read();
	p=read();
	q=read();
	cin>>s;
	for(int i=0;i<=n;i+=p)
	{
		if((n-i)%q==0)
		{
			while(i<n)
			{
				ans.push_back(s.substr(i,q));
				i+=q;	
			}	
			cout<<ans.size()<<endl;
			for(string i:ans)
				cout<<i<<endl;
			return 0;
		} 
		ans.push_back(s.substr(i,p));
	}
	puts("-1");
	return 0;
}