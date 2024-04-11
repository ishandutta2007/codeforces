#include<bits/stdc++.h>
#define pb push_back
#define pii pair<ll,ll>
#define crp make_pair
using namespace std;
typedef long long ll;
typedef double db;
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
ll gcd(ll a,ll b)
{
	while(b){a%=b;swap(a,b);}
	return a;
}
const ll N=1e6+50;
ll n,m=0,tot=0,K;
db ans=0;
map<pii,ll> mp;
ll num[N];
db p[N],s1[N],f1[N],s2[N],f2[N];
vector<db> h[N];
int main()
{
	ll i,j,x,y,gd,id;
	db dis,val,now;
	n=rd();K=rd();
	for(i=1;i<=n;i++)
	{
		x=rd();y=rd();
		if(x==0&&y==0) continue;
		dis=sqrt((db)(x*x+y*y));
		gd=gcd(abs(x),abs(y));
		x/=gd;y/=gd;
		if(!mp.count(crp(x,y))) mp[crp(x,y)]=++m;
		h[mp[crp(x,y)]].pb(dis);
	}
	id=1;
	for(i=2;i<=m;i++) if(h[i].size()>h[id].size()) id=i;
	swap(h[1],h[id]);

	for(i=1;i<=m;i++) 
	{
		num[i]=h[i].size();
		sort(h[i].begin(),h[i].end());
		for(j=0;j<num[i];j++)
		{
			p[++tot]=(K-1-2*(num[i]-j-1))*h[i][j];
		}
	}
	sort(p+1,p+tot+1);
	reverse(p+1,p+tot+1);
	//for(i=1;i<=tot;i++) printf("#%lld %lf\n",i,p[i]);
	val=0;
	for(i=1;i<=min(tot,K);i++) val+=p[i];
	ans=max(ans,val);
	//printf("P %lf\n",val);
	if(n-num[1]<=K)
	{
		//puts("OK");
		val=0;
		for(i=2;i<=m;i++)
		{
			for(j=0;j<num[i];j++)
			{
				val+=(K-1-2*(num[i]-j-1))*h[i][j];
			}
		}
		for(j=0;j<num[1];j++)
		{
			s1[j+1]=s1[j]+h[1][j];
			f1[j+1]=f1[j]+h[1][j]*j-s1[j];
			s2[j+1]=s2[j]+h[1][num[1]-1-j];
			f2[j+1]=f2[j]+s2[j]-h[1][num[1]-1-j]*j;
		}
		for(j=0;j<=K-(n-num[1]);j++)
		{
			x=j;y=K-(n-num[1])-j;
			now=val+f1[x]+f2[y]+(db)x*s2[y]-(db)y*s1[x]+(s1[x]+s2[y])*(db)(n-num[1]);
			//printf("H %lld %lld   %lf  %lf  %lf %lf\n",x,y,now,val,s1[x],s2[y]);
			ans=max(ans,now);
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}