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
int t,n;
string s;
map<string,int> vis; 
queue<string> q;
void solve()
{
	n=read();
	cin>>s;
	vis.clear();
	while(!q.empty())
		q.pop();
	for(int i=0;i<n;i++)
	{
		string ss="";
		for(int l=i;l<n;l++)
		{
			ss+=s[l];
			vis[ss]=1;
		}
	}
	string ss="";
	q.push(ss);
	while(!q.empty())
	{
		string f=q.front();
		q.pop();
		for(char i='a';i<='z';i++)
			q.push(f+i);
		if(f=="")
			continue;
		if(vis[f]==0)
		{
			cout<<f<<endl;
			return ;
		}
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}