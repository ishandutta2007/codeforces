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

ll N;
ll g = 0;

ll gcd(ll x, ll y){
	return (x==0) ? y : gcd(y%x, x);
}

int main(){
	scanf("%lld", &N);
	for(ll i=2; i*i<=N; i++){
		bool tf = true;
		if(N%i==0){
			g = gcd(g, i);
			g = gcd(g, (N/i));
		}
	}
	if(g==0){
		printf("%lld", N);
		return 0;
	}
	else{
		printf("%lld", g);
		return 0;
	}
	return 0;
}