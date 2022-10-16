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
int t,n,l,r,p,cnt,a[200001],b[200001];
bool check()
{
	l=1,r=n;
	deque<int> q;
	while(l<=r)
	{
		if(b[l]<b[r])
			q.push_front(b[l++]);
		else
			q.push_back(b[r--]);
	}
	bool f1=1,f2=1;
	for(int i=1;i<n;i++)
	{
		if(q.front()!=a[i])
			f1=0;
		if(q.front()!=a[i+1])
			f2=0;
		q.pop_front();
	}
	if(!f1&&!f2)
		return 0;
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 1; 
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	l=1,r=n;	
	deque<int> q;
	while(l<=r)
	{
		if(l==r)
		{
			p=l;
			break;
		}
		elif(a[l]<a[r])
			q.push_front(a[l++]);
		else
			q.push_back(a[r--]);
	}
	cnt=0;
	for(int i:q)
		b[++cnt]=i;
	b[++cnt]=a[p];
	if(check())
		return;
	b[1]=a[p];
	cnt=1;
	for(int i:q)
		b[++cnt]=i;
	if(check())
		return ;
	puts("-1");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}