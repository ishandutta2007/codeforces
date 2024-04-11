#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int __int128
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
int n,cnt,tot,oe=1;
char s[40];
map<int,int> mp;
int mul(int x,int y)
{
	int res=0;
	for(int i=0;i<=n;i++)
		res^=(((x>>i)&1)*y)<<i;
	for(int i=n+n;i>n;i--)
		if((res>>i)&1)
			res^=(tot<<(i-n));
	return (long long)res;
}
void write(int x)
{
	if(x<=9)
	{
		putchar('0'+x);
		return ;
	}
	write(x/10);
	putchar('0'+x%10);
}
int solve()
{
	int lim=(1<<18),x=1;
	for(int i=0;i<lim;i++)
	{
		mp[x]=i;
		x=mul(x,2);
		// write(x);
		// cout<<'\n';
	}
	int bse=x;
	for(int i=1;i<=lim;i++)
	{
		if(mp.count(x))
			return lim*i-mp[x];
		x=mul(x,bse);
	}
	return -1;
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	while(n&&s[n]=='0')
		n--;
	if(!n)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(s[i]=='1')
		{
			cnt=i;
			break;
		}
	for(int i=cnt;i<=n;i++)
		s[i-cnt+1]=s[i];
	n+=1-cnt;
	for(int i=1;i<=n;i++)
		if(s[i]=='1')
			tot|=(oe<<(i-1));
	// write(tot);
	// cout<<'\n';
	n--;
	int ans=solve();
	if(ans<0)
		puts("-1");
	else
	{
		write(cnt);
		putchar(' ');
		write(cnt+ans);
	}
	return 0;
}