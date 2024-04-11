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
int n,m,ans,ansx=10000,ansy=10000;
char c[21][21];
map<string,bool> mp;
void check(int x,int y)
{
	mp.clear();
	for(int i=1;i<=n;i+=x)
		for(int l=1;l<=m;l+=y)
		{
			string s;
			for(int j=i;j<i+x;j++)
				for(int k=l;k<l+y;k++)
					s+=c[j][k];
			if(mp[s])
				return ;
			mp[s]=1;
			reverse(ALL(s));
			mp[s]=1;
			if(x==y)
			{
				s="";
				for(int j=l;j<l+y;j++)
					for(int k=i+x-1;k>=i;k--)
						s+=c[k][j];
				mp[s]=1;
				reverse(ALL(s));
				mp[s]=1;
			}
		}
	ans++;
	if(x*y==ansx*ansy)
		if(x<ansx)
		{
			ansx=x;
			ansy=y;
		}
	if(x*y<ansx*ansy)
	{
		ansx=x;
		ansy=y;
	}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			cin>>c[i][l];
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			if(!(n%i)&&!(m%l))
				check(i,l);
	cout<<ans<<"\n"<<ansx<<" "<<ansy;
	return 0;
}