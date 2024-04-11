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
int n,cnt;
array<int,2> a[100002];
signed main()
{
	n=read();
	cnt=n-(n+1)/3;
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++)
		a[i][0]=i;
	for(int i=1;i<=(cnt+1)/2;i++)
	{
		a[i][1]=i*2-1;
		a[i+(cnt+1)/2][1]=i*2;
	}
	for(int i=1;i<=cnt;i++)
		cout<<a[i][0]<<" "<<a[i][1]<<'\n';
	return 0;
}
/*
1100111
1110111
0111111
0011111
1111111
1111111
1111111
*/