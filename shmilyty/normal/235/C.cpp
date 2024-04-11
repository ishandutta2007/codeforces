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
char s[1000001];
int n,m,ans,cnt=1,lst=1,sz[2000001],q[2000001],fa[2000001],len[2000001],num[2000001],vis[2000001],son[2000001][26];
vector<int> v;
int extend(int i)
{
	int x=lst,u=++cnt,c=s[i]-'a';
	lst=u;
	sz[u]=1;
	len[u]=i;
	for(;x&&!son[x][c];x=fa[x])
		son[x][c]=u;
	int y=son[x][c];
	if(x==0)
		return fa[u]=1;
	if(len[y]==len[x]+1)
		return fa[u]=y;
	int p=++cnt;
	fa[p]=fa[y];
	fa[y]=fa[u]=p;
	len[p]=len[x]+1;
	memcpy(son[p],son[y],sizeof(son[y]));
	for(;x&&son[x][c]==y;x=fa[x])
		son[x][c]=p;
	return 0;
} 
void build()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		extend(i);
	for(int i=1;i<=cnt;i++)
		num[len[i]]++;
	for(int i=1;i<=n;i++)
		num[i]+=num[i-1];
	for(int i=cnt;i;i--)
		q[num[len[i]]--]=i;
	for(int i=cnt,u=q[i];i;u=q[--i])
		sz[fa[u]]+=sz[u];
}
signed main()
{
	build();
	m=read();
	while(m--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		int p=1,d=0,c;
		v.clear();
		for(int i=1;i<2*n;i++)
		{
			if(i<=n)
				c=s[i]-'a';
			else
				c=s[i-n]-'a';
			while(p&&!son[p][c])
			{
				p=fa[p];
				d=len[p];
			}
// 			cout<<"d="<<d<<" "<<p<<" "<<len[p]<<endl;
			if(p)
			{
				p=son[p][c];
				d++;
				while(d>n)
				{
					d--;
					if(d<=len[fa[p]])
						p=fa[p];
				}
				if(d>=n&&!vis[p])
				{
					ans+=sz[p];
					vis[p]=1;
					v.push_back(p);
				}
			}
			else
				p=1;
		}
		cout<<ans<< endl;
		for(int i:v)
			vis[i]=0;
	}
	return 0;
}