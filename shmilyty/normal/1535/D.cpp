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
int n,q,k=1,tw[21];
string s;
pair<char,int> tree[1<<21];
void build(int x,int d)
{
	if(d==n)
	{
		tree[x].second=(tree[x].first=='?'?2:1);
		return ;
	}
	build(x*2,d+1);
	build(x*2+1,d+1);
	if(tree[x].first!='1')
		tree[x].second+=tree[x*2+1].second;
	if(tree[x].first!='0')
		tree[x].second+=tree[x*2].second;
}
void modify(int now,int x,int d,char c)
{
	if(now==x)
	{
		tree[x].first=c;
		tree[x].second=0;
		if(d==n)
		{
			tree[x].second=(tree[x].first=='?'?2:1);
			return ;
		}
		if(tree[x].first!='1')
			tree[x].second+=tree[x*2+1].second;
		if(tree[x].first!='0')
			tree[x].second+=tree[x*2].second;
		return ;
	}
	if(s[d]=='1')
		modify(now*2+1,x,d+1,c);
	else
		modify(now*2,x,d+1,c);
	tree[now].second=0;
	if(tree[now].first!='1')
		tree[now].second+=tree[now*2+1].second;
	if(tree[now].first!='0')
		tree[now].second+=tree[now*2].second;
//	cout<<now<<" "<<tree[now].first<<" "<<tree[now].second<<endl;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		k*=2;
	tw[0]=1;
	for(int i=1;i<=n;i++)
		tw[i]=tw[i-1]*2;
	cin>>s;
	for(int i=0;i<s.size();i++)
		tree[k-i-1]=make_pair(s[i],0);
	build(1,1);
	q=read();
	while(q--)
	{
		int x=read();
		char c;
		cin>>c;
		s="";
		int xx=k-x;
		while(xx)
		{
			s+=(xx%2+'0');
			xx/=2;
		}
		reverse(s.begin(),s.end());
//		cout<<s<<endl;
		modify(1,k-x,1,c);
		cout<<tree[1].second<<endl;
	}
	return 0;
}