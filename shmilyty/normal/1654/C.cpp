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
int t,n,sum,a[200001];
map<int,int> num;
bool dfs(int cnt)
{
//	cout<<cnt<<endl;
	if(cnt==0)
		return 0;
	if(cnt==1&&num[1]==0)
		return 0;
	int x=cnt/2,y=cnt-x;
	if(num[y])
		num[y]--;
	else
		if(!dfs(y))
			return 0;
	if(num[x])
		num[x]--;
	elif(!dfs(x))
		return 0;
	return 1;
}
void solve()
{
	n=read();
	if(n==1)
	{
		a[1]=read();
		puts("Yes"); 
		return ;
	}
	sum=0;
	num.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		num[a[i]]++;
		sum+=a[i];
	}
	if(dfs(sum))
		puts("Yes");
	else
		puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}