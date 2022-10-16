#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,t[200001],L[100001],R[100001];
array<int,3> a[100001]; 
void modify(int x)
{
	for(;x<=2*n;x+=lowbit(x))
		t[x]++;
}
int query(int x)
{
	int res=0;
	for(;x;x^=lowbit(x))
		res+=t[x];
	return res;
}
bool cmp(array<int,3> x,array<int,3> y)
{
	return x[1]<y[1];
}
/*
L_x: x'>x&&y'<y
R_x:
 - x'<x&&y'>y
 - x'>y&&y'>y
 - x'<x&&y'<x
*/
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(x>y)
			swap(x,y);
		a[i]={x,y,i};
	}
	sort(a+1,a+1+n);
	for(int i=n;i;i--)
	{
		L[a[i][2]]=query(a[i][1]-1);
		modify(a[i][1]);
	}
	fill(t+1,t+1+2*n,0);
	for(int i=1;i<=n;i++)//case 1
	{
		R[a[i][2]]=i-1-query(a[i][1]);
		modify(a[i][1]);
	}
	fill(t+1,t+1+2*n,0);
	for(int i=1;i<=n;i++)//case 3
	{
		R[a[i][2]]+=query(a[i][0]-1);
		modify(a[i][1]);
	}
	sort(a+1,a+1+n,cmp);
	fill(t+1,t+1+2*n,0);
	for(int i=n;i;i--)//case 2
	{
		R[a[i][2]]+=(n-i)-query(a[i][1]);
		modify(a[i][0]);
	}
	int ans=n*(n-1)*(n-2)/6,res=0;
	for(int i=1;i<=n;i++)
	{
		ans-=L[i]*R[i];
		res+=(L[i]+R[i])*(n-1-L[i]-R[i]); 
	}
	cout<<ans-res/2;
	return 0;
}