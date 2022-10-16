#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int n,f[200001][26];
char s[200001],g[200001][26],ans[200001]; 
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int l=0;l<26;l++)
		{
			int minn=INF;
			char c;
			for(char j='a';j<='z';j++)
				if(j-'a'!=l)
					if(minn>f[i-1][j-'a'])
					{
						minn=f[i-1][j-'a'];
						c=j;
					}
			f[i][l]=minn;
			if(s[i]-'a'!=l)
				f[i][l]++;
			g[i][l]=c;
//			cout<<i<<" "<<l<<" "<<c<<endl;
		}
	int minn=INF;
	for(char i='a';i<='z';i++)
		if(minn>f[n][i-'a'])
		{
			minn=f[n][i-'a'];
			ans[n]=i;
		}
//	cout<<ans[n]<<endl;
	for(int i=n;i>1;i--)
		ans[i-1]=g[i][ans[i]-'a'];
	for(int i=1;i<=n;i++)
		cout<<ans[i];
	return 0;
}