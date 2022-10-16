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
const int INF=1e18;
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
int n,ran,lim,a[1010],b[1010],L[1010],R[1010];
array<int,2> ans[1010];
vector<int> v,v1,v2;
mt19937 rng(time(NULL));
int query(int i,int x)
{
	cout<<"? "<<i<<' '<<x<<endl;
	return read();
}
void solve(int l,int r,int ll,int rr)
{
	if(l==r)
	{
		ans[a[l]]={ll,rr};
		return ;
	}
	int mid1=(l+r)>>1,mid2,l1=l,r1=r;
	lim=ran/n*mid1;
	// cout<<lim<<'\n';
	// cout<<mid1<<'\n';
	while(l1<=r1)
	{
		// cout<<l1<<" "<<r1<<'\n';
		int i=rng()%(r1-l1+1)+l1;
		int lb=ll,rb=rr;
		while(lb<=rb)
		{
			int m=(lb+rb)>>1;
			if(query(a[i],m)<lim)
				lb=m+1;
			else
				rb=m-1;
		}
		// cout<<lb<<'\n';
		v.clear();
		v1.clear();
		v2.clear();
		for(int i=l1;i<=r1;i++)
		{
			int A=query(a[i],lb);
			if(A>lim)
				v.push_back(a[i]);
			elif(A==lim)
				v1.push_back(a[i]);
			else
				v2.push_back(a[i]);
		}
		// puts("ok");
		// for(int i:v)
			// cout<<i<<" ";
		// cout<<'\n';
		// for(int i:v1)
			// cout<<i<<" ";
		// cout<<'\n';
		// for(int i:v2)
			// cout<<i<<" ";
		// cout<<'\n';
		v1.insert(v1.begin(),ALL(v));
		// v1.insert(prev(v1.end()),ALL(v2));
		for(int i:v2)
			v1.push_back(i);
		// for(int i:v1)
			// cout<<i<<" ";
		// cout<<'\n'<<'\n';
		assert(v1.size()==r1-l1+1);
		for(int i=0;i<=r1-l1;i++)
			a[i+l1]=v1[i];
		if(l1+v.size()<=mid1&&mid1<=r1-v2.size())
		{
			mid2=lb;
			break;
		}
		if(l1+v.size()<mid1)
			l1=l1+v.size()+1;
		else
			r1=l1+v.size()-1;
	}
	// puts("ok");
	// int mid2=nth_element(a+l,a+mid1,a+1+r,cmp);
	solve(l,mid1,ll,mid2);
	solve(mid1+1,r,mid2,rr);
}
signed main()
{
	n=read();
	ran=read();
	for(int i=1;i<=n;i++)
		a[i]=i;
	solve(1,n,0,INF);
	cout<<"!"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
	return 0;
}