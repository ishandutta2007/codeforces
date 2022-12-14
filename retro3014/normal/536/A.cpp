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
const int MAX_N = 1;

ll A, B;
int N;
ll L, T, M;

bool chk(ll x){
	if(x<L)	return false;
	if(T-A<0)	return false;
	if(x > (T-A)/B + 1){
		return false;
	}
	ll sum = (A-B) * (x - L + 1) + B * (x * (x+1) / 2 - (L-1) * L / 2);
	return sum <= T*M;
}

int main(){
	scanf("%lld%lld%d", &A, &B, &N);
	while(N--){
		scanf("%lld%lld%lld", &L, &T, &M);
		ll s = L, e = T, m;
		while(s<e){
			m = (s+e)/2+1;
			if(chk(m)){
				s = m;
			}else{
				e = m-1;
			}
		}
		if(chk(s)){
			printf("%lld\n", s);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}