#include<bits/stdc++.h>
#define pf(x) ((x)*(x))
using namespace std;
typedef double db;
const db W=1e7;
struct Point{db x,y;};
db DIS(Point a,Point b){return sqrt(pf(a.x-b.x)+pf(a.y-b.y));}
struct Circle{Point o;db r;};
typedef long long ll;
const ll N=210,V=N*N,B=(ll)1e9;
ll n,C,ans=0;
ll fa[N];
ll getft(ll x){if(x==fa[x]) return x;else return fa[x]=getft(fa[x]);}
void link(ll x,ll y)
{
	ll af,bf;
	af=getft(x);bf=getft(y);
	if(af==bf) return ;
	C--;
	fa[af]=bf;
}
Circle h[N];
struct Hmap
{
	map<ll,bool> mp; 
	void ins(Point p)
	{
		ll x,y,vl;
		x=floor(p.x*W+0.5);y=floor(p.y*W+0.5);
		vl=x*B+y;
		mp[vl]=1;
	}
}hmp[N];
void Solve(ll id1,ll id2)
{
	db d,alpha,sita;
	Circle a=h[id1],b=h[id2];
	Point p1,p2;
	if(a.o.x>b.o.x||(a.o.x==b.o.x&&a.o.y>b.o.y)) swap(a,b),swap(id1,id2);
	if(pf(a.r+b.r)<pf(a.o.x-b.o.x)+pf(a.o.y-b.o.y)) return ;
	if(pf(a.o.x-b.o.x)+pf(a.o.y-b.o.y)<pf(a.r-b.r)) return ;
	d=DIS(a.o,b.o);
	link(id1,id2);
	sita=acos((pf(d)+pf(a.r)-pf(b.r))/(2.0*d*a.r));
	alpha=atan2(b.o.y-a.o.y,b.o.x-a.o.x);
	p1=(Point){a.o.x+cos(alpha+sita)*a.r,a.o.y+sin(alpha+sita)*a.r};
	p2=(Point){a.o.x+cos(alpha-sita)*a.r,a.o.y+sin(alpha-sita)*a.r};
	hmp[id1].ins(p1);hmp[id1].ins(p2);
	hmp[id2].ins(p1);hmp[id2].ins(p2);
	hmp[0].ins(p1);hmp[0].ins(p2);
	//printf("#%lld %lld\n",id1,id2);
}
int main()
{
	ll i,j;
	cin>>n;
	C=n;
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++)
	{
		cin>>h[i].o.x>>h[i].o.y>>h[i].r;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			Solve(i,j);
		}
	}
	for(i=1;i<=n;i++) ans+=hmp[i].mp.size();
	ans-=hmp[0].mp.size();
	ans+=C+1;
	cout<<ans;
	return 0;
}