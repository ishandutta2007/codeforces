#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
struct Point{ll x,y;};
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
ll cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
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
const ll N=5050;
ll n,m,ans=0;
Point bp;
Point p[N],h[N];
struct Data{ll id;db w;}f[N];
bool cmp(const Data &a,const Data &b){return a.w<b.w;}
ll C(ll a,ll b)
{
	if(a<b) return 0;
	ll ret=1,i;
	for(i=0;i<b;i++) ret*=a-i;
	for(i=1;i<=b;i++) ret/=i;
	return ret;
}
int main()
{
	ll i,j,top,num;
	cin>>n;
	for(i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	for(i=1;i<=n;i++)
	{
		m=0;
		bp=p[i];
		for(j=1;j<=n;j++)
		{
			if(i!=j) f[++m]=(Data){j,atan2(p[j].y-bp.y,p[j].x-bp.x)};
		}
		sort(f+1,f+m+1,cmp);
		for(j=1;j<=m;j++) h[j]=p[f[j].id];
		for(j=1;j<=m;j++) h[j+m]=h[j];
		//printf("\nP%lld %lld\n",bp.x,bp.y);
		//for(j=1;j<=m;j++) printf("#%lld  %lld %lld\n",j,h[j].x,h[j].y);
		for(j=1,top=1;j<=m;j++)
		{
			top=max(top,j);
			while(cross(h[j]-bp,h[top+1]-bp)>0) top++;
			num=top-j;
			ans+=C(num,3);
			//printf("S%lld %lld\n",ans,num);
		}
	}
	ans=C(n,5)*5ll-ans;
	cout<<ans;
	return 0;
}