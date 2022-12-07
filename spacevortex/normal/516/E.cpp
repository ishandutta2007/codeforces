#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=2e5+50,B=2e5+5;
ll n,m,D,num,ans=0,tot,bx,by;
vector<ll> vec[N][2];
map<ll,ll> mp;
ll gcd(ll a,ll b)
{
	while(b) 
	{
		a%=b;swap(a,b);
	}
	return a;
}
void exgcd(ll a,ll b)
{
	if(b==0)
	{
		bx=1;by=0;return ;
	}
	ll nx,ny;
	exgcd(b,a%b);
	nx=by;ny=bx-(a/b)*by;
	bx=nx;by=ny;
}
struct Node
{
	ll id,dis,rk;
}p[N];
bool cmp(const Node &a,const Node &b)
{
	return a.rk<b.rk;
}
ll solve(ll n,ll m,vector<ll> A,vector<ll> B)
{
	//printf("solve %lld %lld\n",n,m);
	ll ans=-1,i,asi,bsi,w,x;
	map<ll,ll> ::iterator ni;
	
	mp.clear();
	asi=A.size();bsi=B.size();
	for(i=0;i<asi;i++) mp[A[i]]=A[i];
	for(i=0;i<bsi;i++)
	{
		x=B[i];w=x%n;
		if(!mp.count(w)) mp[w]=x,ans=max(ans,x);
	}
	tot=0;
	ni=mp.begin();
	while(ni!=mp.end())
	{
		tot++;
		p[tot].id=ni->first;p[tot].dis=ni->second;
		ni++;
	}

	p[1].rk=0;
	for(i=2;i<=tot;i++)
	{
		exgcd(m,n);
		//printf("S%lld %lld  %lld %lld\n",m,n,bx,by);
		bx=((bx%n)*(p[i].id-p[1].id)%n+n)%n;
		p[i].rk=bx;
	}
	sort(p+1,p+tot+1,cmp);
	p[tot+1]=p[1];p[tot+1].rk=n;
	for(i=1;i<=tot;i++)
	{
		//printf("#%lld %lld %lld   %lld\n",i,p[i].id,p[i].dis,p[i].rk);
		if(p[i].rk+1<p[i+1].rk)
		{
			ans=max(ans,p[i].dis+(p[i+1].rk-p[i].rk-1)*m);
		}
	}
	//printf("ret %lld\n",ans);
	return ans;
}
int main()
{
	ll i,x,val;
	n=rd();m=rd();
	D=gcd(n,m);
	if(D>B) 
	{
		puts("-1");
		return 0;
	}
	n/=D;m/=D;
	num=rd();
	for(i=1;i<=num;i++)
	{
		x=rd();
		vec[x%D][0].pb(x/D);
	}
	num=rd();
	for(i=1;i<=num;i++)
	{
		x=rd();
		vec[x%D][1].pb(x/D);
	}
	for(i=0;i<D;i++)
	{
		if(vec[i][0].empty()&&vec[i][1].empty())
		{
			puts("-1");
			return 0;
		}
		sort(vec[i][0].begin(),vec[i][0].end());
		sort(vec[i][1].begin(),vec[i][1].end());
		val=-1;
		val=max(val,solve(n,m,vec[i][0],vec[i][1]));
		val=max(val,solve(m,n,vec[i][1],vec[i][0]));
		if(val!=-1) ans=max(ans,i+val*D);
	}
	printf("%lld\n",ans);
	return 0;
}