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
int l1,l2,z[700001];
string s,x;
array<int,3> pw[700001],xx,sum[500001];
int mod[]={998244353,1000000007,597804841};
void init(string s)
{
	int m=s.size();
	int l=0,r=0;
	for(int i=1;i<m;i++)
	{
		if(i<=r)
			z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<m&&s[i+z[i]]==s[z[i]])
			z[i]++;
		if(i+z[i]-1>r)
		{
			l=i;
			r=i+z[i]-1;
		}
	}
}
array<int,3> mul(array<int,3> x,array<int,3> y)
{
	array<int,3> res;
	for(int i=0;i<3;i++)
		res[i]=x[i]*y[i]%mod[i];
	return res;
}
array<int,3> add(array<int,3> x,array<int,3> y)
{
	array<int,3> res;
	for(int i=0;i<3;i++)
		res[i]=(x[i]+y[i])%mod[i];
	return res;
}
array<int,3> mus(array<int,3> x,array<int,3> y)
{
	array<int,3> res;
	for(int i=0;i<3;i++)
		res[i]=(x[i]-y[i]+mod[i])%mod[i];
	return res;
}
array<int,3> get(int x,int y)
{
	return mus(sum[y],mul(sum[x],pw[y-x]));
}
bool equ(array<int,3> x,array<int,3> y)
{
	for(int i=0;i<3;i++)
		if(x[i]!=y[i])
			return 0;
	return 1;
}
bool pri(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 1;
	return 0;
}
int R()
{
	return rand()<<15|rand();
}
signed main()
{
	srand(time(NULL));
	for(int i=0;i<3;i++)
	{
		int q=R();
		while(pri(q))
			q=R();
		mod[i]=q;
	}
	cin>>s>>x;
	l1=s.size();
	l2=x.size();
	string ss;
	ss=x+"#"+s;
	init(ss);
	pw[0]={1,1,1};
	for(int i=1;i<=7e5;i++)
		pw[i]=mul(pw[i-1],{10,10,10});
	for(int i=0;i<l1;i++)
		sum[i+1]=add(mul(sum[i],{10,10,10}),{s[i]-'0',s[i]-'0',s[i]-'0'});
	for(int i=0;i<l2;i++)
		xx=add(mul(xx,{10,10,10}),{x[i]-'0',x[i]-'0',x[i]-'0'});
//	cout<<xx[0]<<" "<<xx[1]<<" "<<xx[2]<<endl;
	if(l2>1)
		for(int i=0;i+2*(l2-1)<=l1;i++)
			if(equ(add(get(i,i+l2-1),get(i+l2-1,i+l2*2-2)),xx))
			{
				cout<<i+1<<" "<<i+l2-1<<endl<<i+l2<<" "<<i+2*l2-2;
				return 0;
			}
	for(int i=0;i+l2<=l1;i++)
	{
		int l=z[l2+i+1];
		for(int j=l2-l-1;j<=l2-l;j++)
			if(j>=1)
			{
//				cout<<i<<" "<<j<<endl; 
				if(i+l2+j<=l1&&equ(add(get(i,i+l2),get(i+l2,i+l2+j)),xx))
				{	
					cout<<i+1<<" "<<i+l2<<endl<<i+l2+1<<" "<<i+l2+j;
					return 0;
				}
				if(i>=j&&equ(add(get(i-j,i),get(i,i+l2)),xx))
				{
					cout<<i-j+1<<" "<<i<<endl<<i+1<<" "<<i+l2;
					return 0;
				}
			}
	}
	return 0;
}