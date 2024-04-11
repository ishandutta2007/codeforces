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
int t,n,f[200001];
pair<int,int> p[200001];
vector<int> ans;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans.clear();
		for(int i=1;i<=n;i++)
			p[i]=make_pair(read(),i);
		sort(p+1,p+1+n);
		for(int i=1;i<=n;i++)
			f[i]=f[i-1]+p[i].first;
		for(int i=n;i>=1;i--)
		{
			ans.push_back(p[i].second);
			if(p[i].first>f[i-1])
				break;
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}