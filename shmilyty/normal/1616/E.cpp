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
int T,n,ans,cnt,tr[100001];
char s[100001],t[100001];
vector<int> v[26];
#define lowbit(x) (x&(-x))
void modify(int x,int v)
{
	for(;x<=n;x+=lowbit(x))
		tr[x]+=v;
}
int query(int x)
{
	int res=0;
	for(;x;x^=lowbit(x))
		res+=tr[x];
	return res;
}
void solve()
{
	n=read();
	scanf("%s%s",s+1,t+1);
	ans=INF;
	cnt=0;
	fill(tr+1,tr+1+n,0);
	for(int i=1;i<=n;i++)
		modify(i,1);
	for(int i=0;i<26;i++)
		v[i].clear();
	for(int i=n;i;i--)
		v[s[i]-'a'].push_back(i);
	for(int i=1;i<=n;i++)
	{
		for(char l='a';l<='z';l++)
		{
			if(l>=t[i])
				break;
			if(v[l-'a'].empty())
				continue;
			int x=v[l-'a'].back();
			ans=min(ans,query(x-1)+cnt);
		}
		if(v[t[i]-'a'].empty())
			break;
		int x=v[t[i]-'a'].back();
		v[t[i]-'a'].pop_back();
		cnt+=query(x-1);
		modify(x,-1); 
	}
	if(ans==INF)
		puts("-1");
	else
		cout<<ans<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}