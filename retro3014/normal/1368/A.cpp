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

int T;

ll A, B, N;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%lld", &A, &B, &N);
		if(A>B){
			ll tmp = A; A = B; B = tmp;
		}
		ll cnt = 0;
		while(B<=N){
			A+=B;
			ll tmp = B; B = A; A = tmp;
			cnt++;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}