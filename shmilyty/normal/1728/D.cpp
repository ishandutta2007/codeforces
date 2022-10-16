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
int T,n,f[2001][2001];
char s[2001];
void solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			f[i][l]=0;
	for(int i=1;i<n;i++)
		if(s[i]==s[i+1])
			f[i][i+1]=0;
		else
			f[i][i+1]=1;
	for(int l=n-3;l>0;l--)
		for(int r=l+3;r<=n;r++)
		{
			int ok1=0,ok2=0,ok3=0;
			if(f[l+1][r-1])
				ok1=f[l+1][r-1];
			elif(s[l]!=s[r])
				ok1=1;
			if(f[l+2][r])
				ok2=f[l+2][r];
			elif(s[l]>s[l+1])
				ok2=-1;
			elif(s[l]<s[l+1])
				ok2=1;
			if(f[l][r-2])
				ok3=f[l][r-2];
			elif(s[r]>s[r-1])
				ok3=-1;
			elif(s[r]<s[r-1])
				ok3=1;
			if(ok1>0&&(ok2>0||ok3>0))
				f[l][r]=1;
			elif((ok1<0)||(ok2<0&&ok3<0))
				f[l][r]=-1;
		}
	if(f[1][n]>0)
		puts("Alice");
	elif(f[1][n]<0)
		puts("Bob");
	else
		puts("Draw");
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}