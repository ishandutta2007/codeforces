#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>
 
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;
 
const int N = 1000001;
ll n,p;
ll w,d;
ll x,y;
 
ll inv(ll cur, ll mod) {
	if(cur==1) return 1;
	return (((mod-1)*(mod/cur)%mod)*inv(mod%cur, mod))%mod;
}
int main(void){
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	//wx+dy=p x+y<=nl
	ll g=__gcd(w,d);
	if(p%g) {printf("-1"); return 0;}
	p/=g, w/=g, d/=g;
	while(y<w) {
	    if(!((d*y-p)%w)) break;
	    y++;
	}
	if(y==w) {printf("-1"); return 0;}
	if(d*y>p) {printf("-1"); return 0;}
	x=(p-d*y)/w;
	if(x+y>n) {printf("-1"); return 0;}
	printf("%lld %lld %lld", x, y, n-x-y);
}