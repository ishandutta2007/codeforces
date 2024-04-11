/*#include<bits/stdc++.h>
#define ld long double
#define ll int
#define pll pair<ll,ll>
#define MP make_pair
#define F first
#define S second
using namespace std;
const ll maxn=1010;
pll dp[maxn][maxn];
bool check[maxn][maxn];
ll gcd(ll a,ll b) {if(b==0) return a;return gcd(b,a%b);}
pll fract(ll a,ll b)
{
ll alamat=1;
if(a==0) return MP(0,1);
if(a*b<0) alamat=-1;
ll g,AA=abs(a),BB=abs(b);
g=gcd(AA,BB);
return MP(alamat*(AA/g),BB/g);
}
pll jam(pll a,pll b)
{
a.first*=b.second;
b.first*=a.second;
return fract(a.first+b.first,b.second*a.second);
}
pll zarb(pll a,pll b){return fract(a.first*b.first,a.second*b.second);}
pll zarb(pll a,ll b){return fract(a.first*b,a.second);}
pll f(ll i,ll j) //what if both i and j are 0?
{
	if(i<0||j<0) return MP(0,1);
	if(i==0&&j==0) return MP(0,1);
	if(j==0) return MP(1,1);
	if(i==0) return MP(0,1);
	if(i+j==2) return MP(1,2);// if i==1 && j==1
	if(check[i][j]) return dp[i][j];
	pll ans1=fract(i,i+j);
	pll ans2=zarb(zarb(fract(j,j+i),fract(j-1,j+i-1)),jam(zarb(fract(j-2,j+i-2),f(i,j-3)),zarb(fract(i,j+i-2),f(i-1,j-2))));
	pll Ans=jam(ans1,ans2);
	check[i][j]=1;
	dp[i][j]=Ans;
	return Ans;
}
int main()
{
	ll w,b;cin>>w>>b;
	pll Ans=f(w,b);
	cout<<setprecision(9);
	cout<<(ld)(Ans.F)/(ld)(Ans.S);
}*/
#include<bits/stdc++.h>
#define ld long double
#define ll int
using namespace std;
const ll maxn=1010;
ld dp[maxn][maxn];
bool check[maxn][maxn];
ld f(ll i,ll j) //what if both i and j are 0?
{
	if(i<0||j<0) return 0;
	if(i==0&&j==0) return 0;
	if(j==0) return (ld)1;
	if(i==0) return (ld)0;
	if(i+j==2) return (ld)(0.5);// if i==1 && j==1
	if(check[i][j]) return dp[i][j];
	ld Ans=((ld)(i)/(ld)(i+j))+((ld)(j)/(ld)(j+i))*(ld)(j-1)/(ld)(j+i-1)*(((ld)(j-2)/(ld)(j+i-2))*f(i,j-3)+((ld)(i)/(ld)(j+i-2))*f(i-1,j-2));
	check[i][j]=1;
	dp[i][j]=Ans;
	return Ans;
}
int main()
{
	ll w,b;cin>>w>>b;
	cout<<setprecision(9);
	cout<<f(w,b);
}