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
const int MAX_N = 100000;

int N, Q, K;
ll sum[MAX_N+1];
ll arr[MAX_N+1];

ll Sum(int x, int y){
	if(x>y)	return 0LL;
	return sum[y]-sum[x-1];
}

int main(){
	scanf("%d%d%d", &N, &Q, &K);
	for(int i=1; i<=N; i++){
		scanf("%lld", &arr[i]);
	}
	for(int i=2; i<N; i++){
		sum[i] = arr[i+1] - arr[i-1] - 2;
		sum[i]+=sum[i-1];
	}
	for(int i=1; i<=Q; i++){
		int L, R;
		scanf("%d%d", &L, &R);
		if(L==R){
			printf("%d\n", K-1);
		}else{
			ll ans = Sum(L+1, R-1);
			ans+=(arr[L+1]-2);
			ans+=(K-arr[R-1]-1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}