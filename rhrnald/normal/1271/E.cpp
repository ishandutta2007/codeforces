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
ll n,m;
ll count(ll lim) {
	lim=lim+lim;
	ll ret=0;
	ll P=2;
	while(lim<=n) {
		ret+=min(n-lim+1, P);
		P=P+P;
		lim=lim+lim;
	}
	return ret;
}
ll find(ll cnt) {
	ll l=0, r=n;
	while(r-l>1) {
		ll mid=(l+r)/2;
		if(count(mid)>=cnt) l=mid;
		else r=mid;
	}
	return l;
}
int main(void){
	scanf("%lld%lld", &n, &m);
	
	ll a1=find(m);
	ll a2=find(m-1);
	if(m==1) a2=n;
	printf("%lld", max(a1+a1,a2));
}