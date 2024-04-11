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
int n,cnt,res,ans,a[500001];
char s[5000001];
signed main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		a[i]=n+1;
	for(int i=n;i;i--)
	{
		if(s[i]=='1')
		{
			cnt++;
			res+=a[cnt]-i;
		}
		else
			while(cnt)
			{
				a[cnt]=i+cnt;
				cnt--;
			}
		ans+=res;
	}
	cout<<ans;
	return 0;
}