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
char s[100001];
int n,k,cnt=1,lst=1,len[200001],num[200001],fa[200001],q[200001],f[200001],sz[200001],son[200001][26];
int extend(int i)
{
	int x=lst,u=++cnt,c=s[i]-'a';
	lst=u;
	sz[u]=1;
	len[u]=i;
	for(;x&&!son[x][c];x=fa[x])
		son[x][c]=u;
	int y=son[x][c];
	if(!x)
		return fa[u]=1;
	if(len[y]==len[x]+1)
		return fa[u]=y;
	int p=++cnt;
	len[p]=len[x]+1;
	fa[p]=fa[y];
	fa[y]=fa[u]=p;
	memcpy(son[p],son[y],sizeof(son[y]));
	for(;x&&son[x][c]==y;x=fa[x])
		son[x][c]=p;
	return 0;
}
void radixsort()
{
	for(int i=1;i<=cnt;i++)
		num[len[i]]++;
	for(int i=1;i<=n;i++)
		num[i]+=num[i-1];
	for(int i=cnt;i;i--)
		q[num[len[i]]--]=i;
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		extend(i);
	radixsort();
	for(int i=cnt,u=q[i];i;u=q[--i])
		sz[fa[u]]+=sz[u];
	int ans=0;
	for(int i=1;i<=cnt;i++)
		ans+=sz[i]*(sz[i]+1)/2*(len[i]-len[fa[i]]);
	cout<<ans;
	return 0;
}