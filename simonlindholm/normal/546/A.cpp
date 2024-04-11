#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ll k, w, n;
	cin >> k >> n >> w;
	// cost k + 2k + ... + wk = k(1 + .. + w) = kw(w+1) / 2
	ll cost = k*w*(w+1) / 2;
	cout << max(cost - n, 0LL) << endl;
}