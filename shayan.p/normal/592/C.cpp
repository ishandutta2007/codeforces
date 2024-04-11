#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll maxn=2e5+10;
const ll mod=1e9+7;
const ll maxim=1e9,Maxim=1e18;
using namespace std;
ll gcd(ll a,ll b){if(b==0) return a;return gcd(b,a%b);}
pll zarb(ll a,ll b)
{
	ll x1=a/maxim,y1=a%maxim,x2=b/maxim,y2=b%maxim,ansx=0,ansy=0;// x bozorg y koochik
	ll q1=y1*y2,q2=y1*x2+x1*y2,q3=x1*x2;
	ansx+=q1/Maxim;ansy+=q1%Maxim;
	ansx+=q2/maxim;ansy+=(q2%maxim)*maxim;
	ansx+=q3;
	return MP(ansx,ansy);
}
int main()
{
	ll t,w,b;cin>>t>>w>>b;ll m=min(w,b);pll lcm=zarb((w/gcd(w,b)),b);
	ll num1,num2;
	if(lcm.F>6) {num1=0;num2=t+1;}
	else {ll LCM=(lcm.F*Maxim)+lcm.S;num1=(t+1)/LCM;num2=(t+1)%LCM;}
	ll soorat=(num1*m)+min(num2,m)-1;
	ll GCD=gcd(soorat,t);
	cout<<soorat/GCD<<"/"<<t/GCD;
}