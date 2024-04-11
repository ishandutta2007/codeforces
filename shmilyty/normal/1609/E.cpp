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
const int N=1<<17;
int n,q,a[N<<1][6];//bcbc/acac/abab
string s;
void push(int x)
{
	for(int i=0;i<3;i++)
		a[x][i]=a[x<<1][i]+a[x<<1|1][i];
	a[x][3]=min(a[x<<1][3]+a[x<<1|1][1],a[x<<1][0]+a[x<<1|1][3]);
	a[x][4]=min(a[x<<1][4]+a[x<<1|1][2],a[x<<1][1]+a[x<<1|1][4]);
	a[x][5]=min({a[x<<1][0]+a[x<<1|1][5],a[x<<1][5]+a[x<<1|1][2],a[x<<1][3]+a[x<<1|1][4]});	
}
void modify(int x,int y)
{
	x+=N;
	for(int i=0;i<6;i++)
		a[x][i]=0;
	a[x][y]=1;
	while(x>1)
	{
		x>>=1;
		push(x);
	}
}
signed main()
{
	n=read();
	q=read();
	cin>>s;
	for(int i=0;i<n;i++)
		modify(i,s[i]-'a');
	while(q--)
	{
		int x=read()-1;
		char c;
		cin>>c;
		modify(x,c-'a');
		cout<<a[1][5]<<'\n';
	}
	return 0;
}