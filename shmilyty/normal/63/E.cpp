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
int n,f[1<<20];
vector<int>G[15]=
{
{0,1,2},{3,4,5,6},{7,8,9,10,11},{12,13,14,15},{16,17,18},
{2,6,11},{1,5,10,15},{0,4,9,14,18},{3,8,13,17},{7,12,16},
{11,15,18},{6,10,14,17},{2,5,9,13,16},{1,4,8,12},{0,3,7}
};
signed main()
{
	for(int i=0;i<19;i++)
	{
		char c;
		cin>>c;
		if(c!='.')
			n|=(1<<i);
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int l=0;l<15;l++)
			for(int j=0;j<G[l].size();j++)
			{
				int x=0;
				for(int k=j;k<G[l].size();k++)
				{
					if(!((i>>G[l][k])&1))
						break;
					x+=(1<<G[l][k]);
					if(f[i-x])
					{
						f[i]=0;
						break;
					}
				}
				if(!f[i])
					break;
			}
	}
	if(f[n])
		puts("Lillebror");
	else
		puts("Karlsson");
	return 0;
}