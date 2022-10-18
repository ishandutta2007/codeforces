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
	cin >> N;
	vi a(N*2);
	rep(i,0,N) cin >> a[i], a[i+N] = a[i];
	ll res = 0;
	rep(k,1,N+1) {
		if (N % k) continue;
		int r = N/k;
		vi t(r);
		int tmp = 0;
		rep(i,0,r) {
			t[i] = tmp;
			if (__gcd(i+1, r) == 1) ++tmp;
		}
		vi gr(N*2);
		rep(i,0,k) {
			int ma = 0;
			rep(j,0,r)
				ma = max(ma, a[i + k*j]);
			rep(j,0,r)
				if (a[i + k*j] == ma) gr[i + k*j] = gr[i + k*j + N] = 1;
		}
		int count = 0;
		vi counts(N);
		for (int i = 2*N; i --> 0; ) {
			if (gr[i]) count++;
			else count = 0;
			if (i < N) counts[i] = min(count, N-1);
		}
		rep(i,0,N) {
			int c = counts[i]/k;
			// c <= (N-1)/k < r
			res += t[c];
			// rep(j,0,c) if (__gcd(j+1, r) == 1) ++res;
			// cout << "found at position " << i << " " << c / k << " possible periods" << endl;
			// res += c / k;
		}
	}
	cout << res << endl;
}