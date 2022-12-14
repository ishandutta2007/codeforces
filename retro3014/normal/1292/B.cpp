
#include <iostream>
#include <stdio.h>
#include <vector>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const ll INFLL = 2e16;
const int MAX_N = 100;

ll x0, y0, ax, ay, bx, by;
vector<pll> vt;
ll X, Y, T;
int ans;

ll zero(ll x){
	return (x>0)?x:-x;
}

int main(){
	scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
	vt.pb({x0, y0});
	while(1){
		x0 = x0*ax+bx;
		y0 = y0*ay+by;
		if(x0>INFLL || y0>INFLL)	break;
		vt.pb({x0, y0});
	}
	scanf("%lld%lld%lld", &X, &Y, &T);
	for(int i=0; i<vt.size(); i++){
		for(int j=i; j<vt.size(); j++){
			ll dist = min(zero(vt[j].first-X)+zero(vt[j].second-Y), zero(vt[i].first-X)+zero(vt[i].second-Y)) + zero(vt[i].first-vt[j].first) + zero(vt[i].second-vt[j].second);
			if(dist<=T){
				ans = max(ans, j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}