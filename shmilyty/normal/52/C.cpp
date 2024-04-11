#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const ll INF=4e18;
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
ll n,m,num,x,y,z,v,h,cnt,d[200001],t[400001];
string s;
void apply(int x,int v)
{
	t[x]+=v;
	if(x<n)
		d[x]+=v;
}
void build(int x)
{
	while(x>1)
	{
		x>>=1;
		t[x]=min(t[x<<1],t[x<<1|1])+d[x]; 
	}
}
void push(int x)
{
	for(int s=h;s;s--)
	{
		int i=x>>s;
		if(d[i]!=0)
		{
			apply(i<<1,d[i]);
			apply(i<<1|1,d[i]);
			d[i]=0;
		}
	}
}
void modify(ll x,ll y,ll v)
{
//	cout<<x<<" "<<y<<" "<<v<<endl;
	if(x>=y)
	{
//		modify(0,n,v);
//		modify(y,x,-v);
		modify(x,n,v);
		modify(0,y,v);
		return ;
	}
	x+=n;
	y+=n;
	ll l=x,r=y;
	for(;x<y;x>>=1,y>>=1)
	{
		if(x&1)
			apply(x++,v);
		if(y&1)
			apply(--y,v);
	}
	build(l);
	build(r-1);
}
ll query(ll x,ll y)
{
	if(x>=y)
		return min(query(x,n),query(0,y));
	x+=n;
	y+=n;
	ll res=INF;
	push(x);
	push(y-1);
	for(;x<y;x>>=1,y>>=1)
	{
		if(x&1)
			res=min(res,t[x++]);
		if(y&1)
			res=min(res,t[--y]);
	}
	return res;
}
int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read();
	h=sizeof(int)*8-__builtin_clz(n);
	for(int i=n;i<2*n;i++)
		t[i]=read();
	for(int i=n-1;i;i--)
		t[i]=min(t[i<<1],t[i<<1|1]);
	m=read();
	while(m--)
	{
		getline(cin,s);
		istringstream s1;
		s1.str(s);
		num=0;
		for(int i=0;i<s.size();i++)
			if(s[i]==' ')
				num++;
		if(num==1)
		{
			s1>>x;
			s1>>y;
			cnt++;
//			cout<<cnt<<" ";
			cout<<query(x,y+1)<<endl;
		}
		else
		{
			s1>>x;
			s1>>y;
			s1>>z;
			if(z!=0)
				modify(x,y+1,z);
//			cout<<endl;
		}
	}
	return 0;
}