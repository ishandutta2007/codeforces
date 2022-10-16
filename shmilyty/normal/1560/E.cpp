#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int T,n,m,cnt,pos,num[26],vis[26],tmp[26];
char t[500001],s[500001],ss[500001],ans[27];
bool check()
{
	pos=1;
	for(int i=1;i<=n;i++)
		ss[i]=s[i];
	for(int i=1;i<=cnt;i++)
	{
		for(int l=1;l<=n;l++)
			if(ss[l]!='@')
				if(ss[l]==t[pos])
					pos++;
				else
					return 0;
		for(int l=1;l<=n;l++)
			if(ss[l]==ans[i])
				ss[l]='@';
	}
	return 1;
}
void solve()
{
	scanf("%s",t+1);
	m=strlen(t+1);
	n=cnt=0;
	memset(num,0,sizeof(num));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
		num[t[i]-'a']++;
	bool flag=1;
	for(int i=m;i;i--)
	{
		if(t[i]!=t[i-1])
			flag=0;
		if(!vis[t[i]-'a'])
		{
			ans[++cnt]=t[i];
			vis[t[i]-'a']=1;
		}
	}
	if(flag)
	{
		printf("%s %c\n",t+1,t[1]);
		return ;
	}
	reverse(ans+1,ans+1+cnt);
	for(int i=1;i<=cnt;i++)
		if(num[ans[i]-'a']%i)
		{
			puts("-1");
			return ;
		}
		else
			num[ans[i]-'a']/=i;
	for(int i=1;i<=m;i++)
	{
		if(!num[t[i]-'a'])
		{
			for(int l=0;l<26;l++)
				if(num[l])
				{
					puts("-1");
					return ;
				}
			break;
		}
		s[++n]=t[i];
		num[t[i]-'a']--;
	}
	if(check())
	{
		for(int i=1;i<=n;i++)
			cout<<s[i];
		cout<<" ";
		for(int i=1;i<=cnt;i++)
			cout<<ans[i];
		cout<<endl;
	}
	else
		puts("-1");
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}