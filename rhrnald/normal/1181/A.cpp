#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a) for(int i=1;i<=a;i++)
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define Fi first
#define Se second
#define INF 87654321
#define IINF 987654321987654321
#define LINF 987654321987654321
//0x3F3F3F3F3F3F3F3Fll
#define sz(v) ((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pq priority_queue
#define BIGMOD 9223372036854775783
#define PI 3.14159265358979
#define eps 1e-7
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<bool,bool> pbb;
typedef pair<ll,ll> pll;
typedef complex<double> base;
typedef pair<bool,int> pbi;
typedef pair<ll,int> pli;
typedef pair<pll,ll> plll;
typedef pair<double,double> pdd;
typedef pair<int,pii> pi;

int main(){
	ll x,y,z;
	scanf("%lld%lld%lld",&x,&y,&z);
	ll cnt=0;
	cnt+=x/z;
	cnt+=y/z;
	x%=z;
	y%=z;
	if(x+y<z){
		printf("%lld %lld\n",cnt,0LL);
	}
	else{
		printf("%lld %lld\n",cnt+1,min(z-x,z-y));
	}
}