#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	ll N, T, K, D;
	cin >> N >> T >> K >> D;
	N = (N + K-1) / K;
	ll t0 = T * N;
	ll cakes1 = (t0-1) / T + max(t0-1 - D, 0LL) / T;
	cout << (cakes1 >= N ? "YES" : "NO") << endl;
	exit(0);
}