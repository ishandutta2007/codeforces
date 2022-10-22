#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

vector<int> primes;

ll f(int n, int j) {
	if (n == 1) return 1;
	if (j >= primes.size()) return INF;
	
	ll ans = INF;
	ll p = primes[j];
       	ll t = 1, i = 0;
	while (INF / p > t) {
		t *= p;
		i++;
		if (n % (i + 1)) continue;
	       	ll k = f(n / (i + 1), j + 1);
		if (INF / k > t) ans = min(ans, k * t);			
	}	

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; primes.size() < 15; i++) if (is_prime(i)) primes.push_back(i);
	cout << f(n, 0) << endl;
	return 0;
}