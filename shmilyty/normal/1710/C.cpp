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
char s[200001];
int n,f[200001][8][8];
const int mod=998244353;
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0][0][7]=1;
	for(int i=0;i<n;i++)
		for(int l=0;l<8;l++)
			for(int j=0;j<8;j++)
				if(f[i][l][j])
				{
					int nxt=0;
					for(int k=0;k<3;k++)
						if((!((j>>k)&1))||(s[i+1]=='1'))
							nxt|=(1<<k);
					// cout<<nxt<<endl;
					for(int k=0;k<8;k++)
						if((k&nxt)==k)
						{
							if(k==1||k==6)
								(f[i+1][l|1][(s[i+1]=='1'?(j&k):j)]+=f[i][l][j])%=mod;
							if(k==2||k==5)
								(f[i+1][l|2][(s[i+1]=='1'?(j&k):j)]+=f[i][l][j])%=mod;
							if(k==3||k==4)
								(f[i+1][l|4][(s[i+1]=='1'?(j&k):j)]+=f[i][l][j])%=mod;
							if(k==0||k==7)
								(f[i+1][l][(s[i+1]=='1'?(j&k):j)]+=f[i][l][j])%=mod;
						}
				}
	int ans=0;
	for(int i=0;i<=7;i++)
		(ans+=f[n][7][i])%=mod;
	cout<<ans;
	return 0;
}