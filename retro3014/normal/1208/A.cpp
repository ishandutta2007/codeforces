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
ll A, B, C;

int main(){
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld", &A, &B, &C);
		if(C%3==0){
			printf("%lld\n", A);
		}else if(C%3==1){
			printf("%lld\n", B);
		}else{
			printf("%lld\n", (A^B));
		}
	}
	return 0;
}