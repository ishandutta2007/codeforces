#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
// const int INF=4e18;
// inline int read()
// {
// 	int x=0;
// 	bool flag=1;
// 	char c=getchar();
// 	while(c<'0'||c>'9')
// 	{
// 		if(c=='-')
// 			flag=0;
// 		c=getchar();
// 	}
// 	while(c>='0'&&c<='9')
// 	{
// 		x=(x<<1)+(x<<3)+c-'0';
// 		c=getchar();
// 	}
// 	return (flag?x:~(x-1));
// }
const int mod=1e9+7,INV=(mod+1)>>1;
int n,cnt=1,ans,res,a[50001],pos[1600001],sz[1600000],ch[1600000][2],w[1600000][30];
long long m;
void ins(int x)
{
	int now=1;
	for(int i=29;~i;i--)
	{
		if(!ch[now][(x>>i)&1])
			ch[now][(x>>i)&1]=++cnt;
		now=ch[now][(x>>i)&1];
		sz[now]++;
		for(int l=29;~l;l--)
			if((x>>l)&1)
				w[now][l]++;	
	}
}
#define C ch[pos[l]][!((a[l]>>i)&1)]
void pls(int &x,int y)
{
	x+=y;
	if(x>=mod)
		x-=mod;
}
signed main()
{
	// n=read();
	// m=read();
	// cin>>m;
	scanf("%d%lld",&n,&m);
	m*=2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ins(a[i]);
		pos[i]=1;
	}
	// cout<<cnt<<'\n';
	// cout<<sz[0]<<'\n';
	for(int i=29;~i;i--)
	{
		long long sum=0;
		for(int l=1;l<=n;l++)
			sum+=sz[C];
		if(sum<m)
		{
			m-=sum;
			for(int l=1;l<=n;l++)
			{
				for(int j=29;~j;j--)
					if((a[l]>>j)&1)
						pls(ans,1ll*(1<<j)*(sz[C]-w[C][j])%mod);
					else
						pls(ans,1ll*(1<<j)*w[C][j]%mod);
				pos[l]=ch[pos[l]][(a[l]>>i)&1];
			}
		}
		else
		{
			res|=(1<<i);
			for(int l=1;l<=n;l++)
				pos[l]=C;
		}
	}
	pls(ans,1ll*m%mod*res%mod);
	printf("%lld", 1ll*ans*INV%mod);
	return 0;
}