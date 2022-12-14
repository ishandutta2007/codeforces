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

const int MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 200000;

int N, K;
int arr[MAX_N+1];

ll ans2=1LL;

int main(){
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}
	ll ans1 = 0LL;
	for(int i=1; i<=K; i++){
		ans1 += (ll)(N+1-i);
	}
	int cnt = -1;
	for(int i=1; i<=N; i++){
		if(arr[i]>=(N+1-K)){
			if(cnt!=-1){
				ans2*=(ll)(cnt+1);
				ans2 = ans2 % MOD;
			}
			cnt = 0;
		}else{
			if(cnt!=-1){
				cnt++;
			}
		}
	}
	printf("%lld %lld", ans1, ans2);
	return 0;
}