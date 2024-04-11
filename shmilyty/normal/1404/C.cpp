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
int n,q,a[300001],ans[300001],t[600001];
array<int,3> v[300001];
int lowbit(int x)
{
	return x&-x;
}
int sum(int x)
{
	int res=0;
	for(;x;x-=lowbit(x))
		res+=t[x];
	return res;
}
void modify(int x,int y)
{
	for(;x<=n;x+=lowbit(x))
		t[x]+=y;
}
int kth(int x)
{
	int res=0;
	for(int i=1<<18;i;i>>=1)
		if(res+i<=n&&x-t[res+i]>0)
		{
			res+=i;
			x-=t[res];
		}
	return res+1;
}
bool cmp(array<int,3> x,array<int,3> y)
{
	return x[1]<y[1];
}
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=i-read();
	for(int i=0;i<q;i++)
	{
		int x=1+read(),y=n-read();
		v[i]={x,y,i};
	}
	sort(v,v+q,cmp);
	int pos=1;
	for(int i=0;i<q;i++)
	{
		while(pos<=v[i][1])
		{
			int k=(a[pos]<0?1:min(kth(pos-a[pos]),pos+1));
			modify(k,1);
			pos++;
		}
		ans[v[i][2]]=v[i][1]-sum(v[i][0]);
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<endl;
	return 0;
}