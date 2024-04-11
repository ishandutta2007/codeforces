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
const int MAX_N = 200000;
const int MAX_K = 20;

int N;
int arr[MAX_N+1];
int cnt[MAX_K+1];

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		for(int j=0; j<MAX_K; j++){
			if(((1<<j)&arr[i])!=0){
				cnt[j]++;
			}
		}
	}
	for(int j=0; j<MAX_K; j++){
		for(int i=1; i<=cnt[j]; i++){
			arr[i] = (arr[i] | (1<<j));
		}
		int t = (1<<MAX_K)-1-(1<<j);
		for(int i=cnt[j]+1; i<=N; i++){
			arr[i] = (arr[i] & t);
		}
	}
	ll ans = 0LL;
	for(int i=1; i<=N; i++){
		ans += (ll)arr[i]*(ll)arr[i];
	}
	printf("%lld\n", ans);
	return 0;
}