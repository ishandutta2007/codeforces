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
int n,k,ans,f[101][101],a[26][101];
string s;
signed main()
{
//	freopen("data.txt","r",stdin);
	n=read();
	k=read();
	cin>>s;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int l=i;l>=0;l--)
		{
			if(!l)
			{
				f[i][0]=1;
				continue;
			}
			int cnt=f[i-1][l-1]-a[s[i-1]-'a'][l];
//			cout<<cnt<<endl; 
			a[s[i-1]-'a'][l]+=cnt;
			f[i][l]=f[i-1][l]+cnt;
		}
	for(int i=n;i>=0;i--)
		if(f[n][i]>=k)
		{
			ans+=k*(n-i);
			k=0;
			break;
		}
		else
		{
			ans+=f[n][i]*(n-i);
			k-=f[n][i];
		}
	if(k)
		puts("-1");
	else
		cout<<ans; 
	return 0;
}