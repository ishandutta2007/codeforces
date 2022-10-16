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
int n,m,l,dx[5],dy[5],px[1<<5],nx[1<<5],py[1<<5],ny[1<<5],f[32][20][20][20][20][2][2];
signed main()
{
	n=read();
	m=read();
	(l=1<<n--)--;
	f[0][0][0][0][0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		dx[i]=read();
		dy[i]=read();
	}
	for(int i=1;i<=l;i++)
		for(int l=0;l<=n;l++)
			if(i>>l&1)
			{
				(dx[l]>0?px:nx)[i]+=abs(dx[l]);
				(dy[l]>0?py:ny)[i]+=abs(dy[l]);
			}
	for(int t=0;t<=30;t++)
		for(int i=0;i<=px[l];i++)
			for(int i1=0;i1<=nx[l];i1++)
				for(int i2=0;i2<=py[l];i2++)
					for(int i3=0;i3<=ny[l];i3++)
						for(int a=0;a<=1;a++)
							for(int b=0;b<=1;b++)
								for(int s=0;s<=l;s++)
									if(!(i+px[s]+i1+nx[s]&1)&&!(i2+py[s]+i3+ny[s]&1))
									{
										int A=a+(i+px[s]&1)>(m>>t&1),B=b+(i2+py[s]&1)>(m>>t&1);
										int x=i+px[s]>>1,X=i1+nx[s]>>1,y=i2+py[s]>>1,Y=i3+ny[s]>>1;
										(f[t+1][x][X][y][Y][A][B]+=f[t][i][i1][i2][i3][a][b])%=mod;
									}
	cout<<(f[31][0][0][0][0][0][0]+mod-1)%mod;
	return 0;
}