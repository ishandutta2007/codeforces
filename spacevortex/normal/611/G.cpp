#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod=1e9+7,inv2=5e8+4;
ll M(ll x){x%=Mod;x+=Mod;if(x>=Mod)x-=Mod;return x;}
ll add(ll a,ll b){a=M(a);b=M(b);a+=b;if(a>=Mod)a-=Mod;return a;}
ll sub(ll a,ll b){a=M(a);b=M(b);a-=b;if(a<0)a+=Mod;return a;}
ll mul(ll a,ll b){a=M(a);b=M(b);return (ll)a*b%Mod;}
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
struct Point{ll x,y;};
ll cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
Point add(Point a,Point b){return (Point){add(a.x,b.x),add(a.y,b.y)};}
Point sub(Point a,Point b){return (Point){sub(a.x,b.x),sub(a.y,b.y)};}
const ll N=1e6+50;
ll n,m,S,ans=0,cnt=0;
Point p[N],sum[N];
ll val[N],s1[N],s2[N];
ld s3[N];
int main()
{
	ll i,top;
	n=rd();m=n*2;
	for(i=1;i<=n;i++)
	{
		p[i].x=rd();p[i].y=rd();
	}
	reverse(p+1,p+n+1);
	for(i=1;i<=n;i++) p[n+i]=p[i];
	for(i=1;i<=m;i++) sum[i]=add(sum[i-1],p[i]);
	for(i=1;i<m;i++)
	{
		val[i]=cross(p[i],p[i+1]);
		s1[i]=add(s1[i-1],mul(i,val[i]));
		s2[i]=add(s2[i-1],val[i]);
		s3[i]=s3[i-1]+val[i];
	}
	S=s2[n];
	for(i=1,top=1;i<=n;i++)
	{
		top=max(top,i);
		while(top<m&&(ld)(s3[top]-s3[i-1]+(ld)cross(p[top+1],p[i]))*2.0<s3[n]) top++;
		if(top==i+1) continue;
		cnt=add(cnt,top-i-1);
		upd(ans,mul(sub(s2[top-1],s2[i-1]),top));
		rdc(ans,sub(s1[top-1],s1[i-1]));
		upd(ans,cross(sub(sum[top],sum[i]),p[i]));
	}
	//cout<<"S"<<S<<"  C"<<cnt<<endl;
	ans=mul(ans,2);
	ans=sub(mul(S,cnt),ans);
	cout<<ans;;
	return 0;
}