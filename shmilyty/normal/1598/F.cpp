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
int n,ans,flag,f[1<<20][2],num[1<<20],g[20][400010];
array<int,2> a[20];
string s;
signed main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(n==2&&s.substr(0,11)==")))()))))()")
			flag=1;
		int cnt=0;
		for(int l=0;l<s.size();l++)
			if(s[l]=='(')
				cnt++;
			else
			{
				cnt--;
				a[i][0]=min(a[i][0],cnt);
			}
		a[i][1]=cnt;
		cnt=0;
		int k=0;
		for(int l=0;l<s.size();l++)
			if(s[l]=='(')
				cnt++;
			else
			{
				cnt--;
				if(cnt<0)
				{
					k++;
					cnt=0;
				}
				if(cnt==0)
					g[i][k]++;
			}
	}
	for(int i=0;i<(1<<n);i++)
		for(int l=0;l<n;l++)
			if((i>>l)&1)
				num[i]+=a[l][1];
	memset(f,-1,sizeof(f));
	f[0][0]=f[0][1]=0;
	for(int i=0;i<(1<<n);i++)
	{
		ans=max(ans,f[i][1]);
		if(num[i]<0)
		{
			ans=max(ans,f[i][0]);
			continue;
		}
		if(f[i][0]==-1)
			continue;
		for(int l=0;l<n;l++)
			if(!(i&(1<<l)))
			{
				if(a[l][0]+num[i]<0)
					f[i|(1<<l)][1]=max(f[i|(1<<l)][1],f[i][0]+g[l][num[i]]);
				else
					f[i|(1<<l)][0]=max(f[i|(1<<l)][0],f[i][0]+g[l][num[i]]);
			}
	}
	if(flag==2)
	{
		cout<<a[0][0]<<" "<<a[0][1]<<" "<<a[1][0]<<" "<<a[1][1]<<" "<<s.substr(0,10)<<endl;
		cout<<g[0][0]<<" "<<g[0][1]<<" "<<g[1][0]<<" "<<g[1][1]<<endl;
		cout<<f[1][0]<<" "<<f[1][1]<<endl;
		cout<<f[2][0]<<" "<<f[2][1]<<endl;
		cout<<f[3][0]<<" "<<f[3][1]<<endl;
	}
	cout<<max(ans,f[(1<<n)-1][0]);
	return 0;
}