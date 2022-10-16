#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
struct node{
	node *son[2];
	bool ok;
}*root;
int n,m,a[300001],vis[1<<20];
void modify(int x)
{
	vector<int> v;
	for(int i=0;i<20;i++,x>>=1)
		v.push_back(x&1);
	reverse(v.begin(),v.end());
	node *cnt=root;
	for(int i=0;i<20;i++)
	{
		if(!cnt->son[v[i]])
			cnt->son[v[i]]=new node();
		cnt=cnt->son[v[i]];
	}
	cnt->ok=1;
}
int query(int x)
{
	vector<int> v;
	for(int i=0;i<20;i++,x>>=1)
		v.push_back(x&1);
	reverse(v.begin(),v.end());
	node *cnt=root;
	int res=0;
	for(int i=0;i<20;i++)
	{
		res<<=1;
		if(!cnt->son[v[i]])
		{
			cnt=cnt->son[v[i]^1];
			res++;
		}
		else
			cnt=cnt->son[v[i]];
	}
	return res;
}
signed main()
{
	n=read();
	m=read();
	root=new node();
	for(int i=1;i<=n;i++)
		vis[read()]=1;
	for(int i=0;i<(1<<20);i++)
		if(!vis[i])
			modify(i);
	int lst=0;
	while(m--)
	{
		lst^=read();
		cout<<query(lst)<<endl;
	}
	return 0;
}