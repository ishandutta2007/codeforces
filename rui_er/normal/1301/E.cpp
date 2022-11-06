#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int N=503;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
ll a[N][N],b[N][N],c[N][N],d[N][N],f[N/2][N][N];
ll x1,x2,y1,y2;
ll s(ll sum[][N],ll x1,ll y1,ll x2,ll y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll n,m,T;
	cin>>n>>m>>T;
	for(ll i=1;i<=n;i++)
	{
		char tmp;
		for(ll j=1;j<=m;j++)
		{
			cin>>tmp;
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(tmp=='R');
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(tmp=='G');
			c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+(tmp=='Y');
			d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(tmp=='B');

		}
	}
	for(ll k=1;k<=250;k++)
	{
		for(ll i=k<<1;i<=n;i++)
		{
			for(ll j=k<<1;j<=m;j++)
			{
				f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];
				ll sa=s(a,i-k-k+1,j-k-k+1,i-k,j-k);
				ll sb=s(b,i-k-k+1,j-k+1,i-k,j);
				ll sc=s(c,i-k+1,j-k-k+1,i,j-k);
				ll sd=s(d,i-k+1,j-k+1,i,j);
				if(sa==k*k and  sb==k*k and sc==k*k and sd==k*k) f[k][i][j]++;
			}
		}
	}
	while(T--)
	{
		cin>>x1>>y1>>x2>>y2;
		ll l=0;
		ll r=min((x2-x1+1)/2,(y2-y1+1)/2);
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			ll best=s(f[mid],x1+mid+mid-1,y1+mid+mid-1,x2,y2);
			if(best>0)l=mid;
			else r=mid-1;
		}
		cout<<l*l*4<<"\n";
	}
	return 0;
}