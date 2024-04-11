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
const int mod=998244353;
int n,ans,xx,yy,f[101][2][20][16][16];
char s[101];
int dfs(int x,bool ok,int r,int m1,int m2)
{
	if(x>n)
		return !r&&(m1&m2);
	int &res=f[x][ok][r+xx][m1][m2];
	if(~res)
		return res;
	res=0;
	for(int i=0;i<10;i++)
		for(int l=0;l<=(!ok?s[x]-'0':9);l++)
		{
			int nr=r*10-i*yy+l*xx,nm1=0,nm2=0;
			if(nr<=-xx||nr>=yy)
				continue;
			if(i&&!(i%xx)&&i<=9/yy*xx)
				nm1|=1<<(i/xx-1);
			if(l&&!(l%yy))
				nm2|=1<<(l/yy-1);
			(res+=dfs(x+1,ok|(l<s[x]-'0'),nr,m1|nm1,m2|nm2))%=mod;
		}
	return res;
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		ans=(ans*10+s[i]-'0')%mod;
	for(xx=1;xx<10;xx++)
		for(yy=xx+1;yy<10;yy++)
			if(__gcd(xx,yy)==1)
			{
				memset(f,-1,sizeof(f));
				(ans+=2*dfs(1,0,0,0,0)%mod)%=mod;
			}
	cout<<ans;
	return 0;
}