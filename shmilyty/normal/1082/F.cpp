#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int n,k,cnt,val[501],dep[501],trie[501][11],f[501][501][11];
string s;
int dfs(int pos,int d,int k)
{
	if(~f[pos][d][k])
		return f[pos][d][k];
	int res=1e9;
	vector<int> a(k+1,0);
	for(int i=0;i<10;i++)
		if(trie[pos][i])
		{
			vector<int> tmp;
			for(int j=0;j<=k;j++)
				tmp.push_back(dfs(trie[pos][i],d,j));
			vector<int> nxt(k+1,1e9);
			for(int i=0;i<=k;i++)
				for(int j=0;i+j<=k;j++)
					nxt[i+j]=min(nxt[i+j],a[i]+tmp[j]);
			a=nxt;
		}
	res=min(res,a[k]);
	res+=val[pos]*(dep[pos]-d);
	if(k)
		res=min(res,dfs(pos,dep[pos],k-1));
	return f[pos][d][k]=res;
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int p=0;
		for(auto &j:s)
		{
			if(!trie[p][j-'0'])
			{
				trie[p][j-'0']=++cnt;
				dep[cnt]=dep[p]+1;
			}
			p=trie[p][j-'0'];
		}
		val[p]+=read();
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(0,0,k);
	return 0;
}