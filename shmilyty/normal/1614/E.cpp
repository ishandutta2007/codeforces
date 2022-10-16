#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
const int N=18000100;
const int mod=1e9+1;
int n,v,rt,cnt,lst,L[N],R[N],t[N];
void modify(int &x,int l,int r,int val)
{
	if(!x)
		x=++cnt;
	t[x]++;
	if(r-l==1)
		return ;
	int mid=(l+r)>>1,sl=mid-l-t[L[x]];
	if(val<sl)
		modify(L[x],l,mid,val);
	else
		modify(R[x],mid,r,val-sl);
}
int query(int x,int l,int r,int val)
{
	if(val<=l||!x)
		return 0;
	if(val>=r)
		return t[x];
	int mid=(l+r)>>1;
	return query(L[x],l,mid,val)+query(R[x],mid,r,val);
}
signed main()
{
	n=read();
	while(n--)
	{
		int T=read();
		if(T>=v)
			modify(rt,0,1<<30,T-v);
		else
			v--;
		if(T>v)
		{
			modify(rt,0,1<<30,T-v-1);
			v++;
		}
		int k=read();
		while(k--)
		{
	    	int x=(lst+read())%mod;
	    	cout<<(lst=v+x-query(rt,0,1<<30,x))<<'\n';
		}
	}
	return 0;
}