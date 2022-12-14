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

int N;
ll M;

int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%lld", &M);
		if(M<=14LL){
			printf("NO\n");
			continue;
		}
		if(M%14LL<=6 && M%14LL>0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}