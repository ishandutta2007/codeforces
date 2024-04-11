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
priority_queue<int> q;
int n,ans,s,x;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		if(x<0)
		{
			while(!q.empty())
			{
				if(s+x>=0)
					break;
				int v=q.top();
				if(v<-x)break;
				q.pop();
				s+=v;
				ans--;
			}
			if(s+x>=0)
			{
				ans++;
				s+=x;
				q.push(-x);
			}
		}
		else 
		{
			s+=x;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}