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

ll K;
ll cnt[10];
char c[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};

int main(){
	scanf("%lld", &K);
	for(int i=0; i<10; i++){
		cnt[i] = 1LL;
	}
	ll N = 1LL;
	int n = 0;
	while(N<K){
		N/=cnt[n];
		cnt[n]++;
		if(K/N<cnt[n]){
			break;
		}
		N*=cnt[n];
		n = (n+1)%10;
	}
	ll ans = 0LL;
	for(int i=0; i<10; i++){
		while(cnt[i]--){
			printf("%c", c[i]);
		}
	}
	return 0;
}