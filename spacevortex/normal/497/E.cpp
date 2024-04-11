#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
using namespace std;
typedef long long ll;
const ll Mod=1e9+7;
ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
ll mul(const ll a,const ll b){return (ll)a*b%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const ll P=32,S=70;
ll n,K,num=0,ans=0;
ll cf[S];
struct Mat
{
	ll v[P][P];
	Mat(){}
	Mat(ll x)
	{
		memset(v,0,sizeof(v));
		if(x==1)
		{
			for(ll i=0;i<=K;i++) v[i][i]=1;
		}
	}
};
Mat f[S][P],pre[P],suf[P];
Mat t;
const Mat operator *(Mat a,Mat b)
{
	Mat c=Mat(0);
	ll i,j,k;
	for(i=0;i<=K;i++)
	{
		for(j=0;j<=K;j++)
		{
			for(k=0;k<=K;k++)
			{
				upd(c.v[i][k],mul(a.v[i][j],b.v[j][k]));
			}
		}
	}
	return c;
}
int main()
{
	ll i,j,x,now;
	cin>>n>>K;
	x=n;
	while(x>0) 
	{
		num++;x/=K;
	}
	cf[0]=1;
	for(i=1;i<num;i++) cf[i]=cf[i-1]*K;
	for(i=0;i<K;i++)
	{
		f[0][i]=Mat(1);
		for(j=0;j<=K;j++) f[0][i].v[i][j]=1;
	}
	
	for(i=1;i<num;i++)
	{
		pre[0]=f[i-1][0];
		for(j=1;j<K;j++) pre[j]=f[i-1][j]*pre[j-1];
		suf[K-1]=f[i-1][K-1];
		for(j=K-2;j>=0;j--) suf[j]=suf[j+1]*f[i-1][j];
		for(j=0;j<K;j++)
		{
			f[i][j]=suf[j];
			if(j>0) f[i][j]=pre[j-1]*f[i][j];
		}
	}
	t=Mat(0);
	t.v[K][0]=1;
	now=0;
	for(i=num-1;i>=0;i--)
	{
		while(n>=cf[i])
		{
			t=f[i][now]*t;
			n-=cf[i];
			now=(now+1)%K;
		}
	}
 
	ans=1;
	for(i=0;i<K;i++) upd(ans,t.v[i][0]);
	cout<<ans;
	return 0;
}