#pragma GCC optimize ("Ofast") 
#include<bits/stdc++.h>
#define int long long
using namespace std; 
inline int read()
{
	int x=0;
	bool flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return (flag?x:~(x-1)); 
}
int t,n,a[200001],tr[800001],lzy[800001];
vector<int> v;
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
void add(int x,int y)
{
	tr[x]+=y;
	lzy[x]+=y;	
} 
void pushdown(int x)
{
	if(!lzy[x])
		return ;
	add(2*x+1,lzy[x]);
	add(2*x+2,lzy[x]);
	lzy[x]=0;
}
void pushup(int x)
{
	tr[x]=min(tr[2*x+1],tr[2*x+2]);
}
void build(int x,int l,int r)
{
	lzy[x]=0;
	if(l==r)
	{
		tr[x]=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(x*2+1,l,mid);
	build(x*2+2,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int L,int R,int a)
{
	if(L<=l&&r<=R)
	{
		add(x,a);
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(L<=mid)
		modify(x*2+1,l,mid,L,R,a);
	if(R>=mid+1)
		modify(x*2+2,mid+1,r,L,R,a);
	pushup(x);
}
int query(int x,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
		return tr[x];
	int mid=(l+r)>>1,ans=114514114514114514;
	pushdown(x);
	if(L<=mid)
		ans=min(ans,query(x*2+1,l,mid,L,R));
	if(R>=mid+1)
		ans=min(ans,query(x*2+2,mid+1,r,L,R));
	return ans;
}
void solve()
{
	n=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	int ans=0;
	build(0,0,n-1);
	v.clear();
	for(int i=0;i<n;i++)
		if(a[i]>=0)
		{
			ans++;
			modify(0,0,n-1,i,n-1,a[i]);
		}
		else
			v.push_back(i);
	sort(v.begin(),v.end(),cmp);
	for(int i:v)
		if(query(0,0,n-1,i,n-1)+a[i]>=0)
		{
			ans++;
			modify(0,0,n-1,i,n-1,a[i]);
		}
	cout<<ans<<endl;
}
signed main()
{
	solve();
	return 0;
}