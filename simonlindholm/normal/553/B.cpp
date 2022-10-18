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
	cin.sync_with_stdio(false);
	int N;
	ll K;
	cin >> N >> K;
	--K;
	vi v(N);
	rep(i,0,N)
		v[i] = i+1;
	vector<ll> f(N);
	f[0] = f[1] = 1;
	rep(i,2,N)
		f[i] = f[i-1] + f[i-2];
	rep(i,0,N-1) {
		ll m = f[N-1-i];
		if (m <= K) {
			K -= m;
			swap(v[i], v[i+1]);
			++i;
		}
	}
	rep(i,0,N)
		cout << v[i] << ' '; cout << endl;
}