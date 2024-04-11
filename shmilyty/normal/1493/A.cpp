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
int t,n,k;
vector<int> ans;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		ans.clear();
		for(int i=n;i>k;i--)
			ans.push_back(i);
		for(int i=k-1;i*2+1>k;i--)
			ans.push_back(i);
		cout<<ans.size()<<endl;
		for(int i:ans)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}