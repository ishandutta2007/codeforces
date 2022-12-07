#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod=1e9+7;
ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
ll mul(const ll a,const ll b){return (ll)a*b%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1ll) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;  
	}
	return ras;
}
const ll N=110,M=3050;
ll n,m=0;
ll A[N],B[N],pl[M];
void insert(ll n)
{
	ll i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i!=0) continue;
		pl[++m]=i;
		while(n%i==0) n/=i;
	}
	if(n>1) pl[++m]=n;
}
struct Comb
{
	ll a[M],b[M];
	Comb(){memset(a,0,sizeof(a));memset(b,0,sizeof(b));}
}h[N];
Comb build(ll A,ll B)
{
	ll i;
	Comb f;
	for(i=1;i<=m;i++)
	{
		while(A%pl[i]==0) f.a[i]++,A/=pl[i];
		while(B%pl[i]==0) f.b[i]++,B/=pl[i];
	}
	return f;
}
ll bx,by;
ll exgcd(ll a,ll b)
{
	if(b==0)
	{
		bx=1;by=0;return a;
	}
	ll nx,ny,tmp;
	tmp=exgcd(b,a%b);
	nx=by;ny=bx-(a/b)*by;
	bx=nx;by=ny;
	return tmp;
}
ll smul(ll a,ll b,ll Mod)
{
	return ((a*b-((ll)((ld)a*b/Mod)*Mod))%Mod+Mod)%Mod;
}
Comb merge(Comb h1,Comb h2)
{
	ll i,j,k,cs,x,y,d,der,pd1,pd2,w,now,pd;
	static ll a[M][4];
	Comb f;
	memset(a,0,sizeof(a));
	pd1=pd2=0;
	for(i=1;i<=m;i++)
	{
		a[i][1]=h1.b[i];a[i][2]=-h2.b[i];a[i][3]=h2.a[i]-h1.a[i];
		if(a[i][1]) pd1=1;
		if(a[i][2]) pd2=1;
	}
	if(pd1==0&&pd2==0)
	{
		for(i=1;i<=m;i++)
		{
			if(a[i][3])
			{
				puts("-1");exit(0);
			}
		}
		for(i=1;i<=m;i++) f.a[i]=h1.a[i],f.b[i]=0;
		return f;
	}
	if(pd1==0||pd2==0)
	{
		pd=0;
		for(i=1;i<=m;i++)
		{
			if(a[i][1]+a[i][2]) 
			{
				if(a[i][3]%(a[i][1]+a[i][2])!=0)
				{
					puts("-1");exit(0);
				}
				now=a[i][3]/(a[i][1]+a[i][2]);
				if(pd==0) w=now,pd=1;
				else if(now!=w) {puts("-1");exit(0);}
			}
		}
		for(i=1;i<=m;i++) f.a[i]=(pd2?h1.a[i]:h2.a[i]),f.b[i]=0;
		return f;
	}
	for(i=1;i<=2;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			if(a[j][i]) 
			{
				for(k=i;k<=3;k++) swap(a[i][k],a[j][k]);
			}
		}
		if(a[i][i]==0) continue;
		for(j=i+1;j<=m;j++)
		{
			if(i==j) continue;
			while(a[i][i]&&a[j][i])
			{
				cs=a[j][i]/a[i][i];
				for(k=i;k<=3;k++) a[j][k]-=cs*a[i][k];
				for(k=i;k<=3;k++) swap(a[i][k],a[j][k]);
			}
			if(a[i][i]==0) for(k=i;k<=3;k++) swap(a[i][k],a[j][k]);
		}
	}
	for(i=1;i<=m;i++) 
	{
		if(a[i][1]==0&&a[i][2]==0&&a[i][3]>0) 
		{
			puts("-1");exit(0);
		}
	}
	
	if(a[2][2]==0)
	{
		
		d=exgcd(a[1][1],a[1][2]);
		if(a[1][3]%d!=0)
		{
			puts("-1");exit(0);
		}
		der=abs(a[1][2]/d);
		bx=smul(bx%der,(a[1][3]/d)%der,der);
		
		
		der=abs(a[1][1]/d);
		by=smul(by%der,(a[1][3]/d)%der,der);
		bx=max(bx,(a[1][3]-a[1][2]*by)/a[1][1]);
		for(i=1;i<=m;i++) f.a[i]=h1.a[i]+bx*h1.b[i],f.b[i]=abs(a[1][1]/d*a[1][2]);
		return f;
	}
	else
	{
		if(a[1][3]%a[1][1]!=0||a[2][3]%a[2][2]!=0)
		{
			puts("-1");exit(0);
		}
		else
		{
			y=a[2][3]/a[2][2];
			x=(a[1][3]-y*a[1][2])/a[1][1];
			if(x<0||y<0)
			{
				puts("-1");exit(0);
			}
			for(i=1;i<=m;i++) f.a[i]=h1.a[i]+x*h1.b[i],f.b[i]=0;
			return f;
		}
	}
}
ll qry(Comb a)
{
	ll ans=1,i;
	for(i=1;i<=m;i++) 
	{
		ans=mul(ans,power(pl[i],a.a[i]));
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>A[i]>>B[i];
		insert(A[i]);insert(B[i]);
	}
	sort(pl+1,pl+m+1);
	m=unique(pl+1,pl+m+1)-pl-1;
	for(i=1;i<=n;i++) h[i]=build(A[i],B[i]);
	for(i=n-1;i>=1;i--) 
	{
		h[i]=merge(h[i],h[i+1]);
		for(j=1;j<=m;j++)
		{
			if(h[i].a[j]<0)
			{
				puts("-1");exit(0);
			}
		}
	}
	cout<<qry(h[1]);
	return 0;
}