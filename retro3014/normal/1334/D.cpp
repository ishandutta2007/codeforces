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
ll N, L, R;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld", &N);
		scanf("%lld%lld", &L, &R);
		ll n=1;
		while(L<=R){
			while(n!=N && L>(N-n)*2LL){
				L-=(N-n)*2LL;
				R-=(N-n)*2LL;
				n++;
			}
			if(n==N){
				printf("1");
				break;
			}
			if(L%2==1){
				printf("%lld ", n);
			}else{
				printf("%lld ", (L/2)+n);
			}
			L++;
		}
		printf("\n");
	}	
	return 0;
}