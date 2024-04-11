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
	int N, K;
	cin >> N >> K;
	vi a(N);
	rep(i,0,N) cin >> a[i];
	ll prev = 0;
	ll res = 0;
	rep(i,0,N) {
		if (prev > 0 && prev + a[i] <= K) {
			res++;
			prev = 0;
		} else {
			ll cur = a[i] + prev;
			res += cur / K;
			cur %= K;
			prev = cur;
		}
	}
	if (prev > 0) res++;
	cout << res << endl;
}