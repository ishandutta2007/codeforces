#include <bits/stdc++.h>

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
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000;

int T, N;


ll query(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	ll r; scanf("%lld", &r);
	return r;
}

void ans(int x, int y, int z){
	printf("! %d %d %d\n", x, y, z);
	fflush(stdout);
	return;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		ll mx = query(1, N);
		int x, y, z;
		int s = 1, e = N, m;
		while(s<e){
			m = (s+e)/2;
			if(query(1, m)==mx){
				e = m;
			}else{
				s = m+1;
			}
		}
		z = s;
		ll mx2 = query(1, z-1);
		y = z - (mx - mx2);
		ll mx3 = query(1, y-1);
		ll mx4 = query(1, y-2);
		x = y - 1 - (mx3 - mx4);
		ans(x, y, z);
	}
	return 0;
}