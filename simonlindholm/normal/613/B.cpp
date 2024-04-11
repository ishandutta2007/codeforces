#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int N;
	ll A, cf, cm, m;
	cin >> N >> A >> cf >> cm >> m;
	vector<pair<ll, int>> origA(N);
	rep(i,0,N)
		cin >> origA[i].first, origA[i].second = i;
	sort(all(origA));

	tuple<ll, int, ll, int> res{-1, -1, -1, -1};
	{
	vector<ll> a(N);
	rep(i,0,N) a[i] = origA[i].first;
	a.push_back(A);
	ll part = 0;
	vector<ll> partsum(N);
	rep(i,0,N) {
		part += a[i];
		partsum[i] = part;
	}
	auto calc = [&](int k) -> ll {
		// spend m on k first.
		if (k == 0) return a[0];
		ll p = partsum[k-1];
		ll raiseto = a[k-1] * k;
		assert(p <= raiseto);
// cerr << k << " would cost " << raiseto - p << " have " << m << endl;
		if (raiseto - p > m) {
// cerr << k << " no!" << endl;
			return -1; // cannot!
		}
		ll tospend = m - (raiseto - p);
		ll extra = min(a[k] - a[k-1], tospend / k);
		return extra + a[k-1];
	};
	rep(i,0,N+1) {
		// raise i to max
		// then we have m left to spend. say we spend it on the first k. hi is impossible.
// cerr << "trying with " << m << endl;
		int lo = 0, hi = N-i+1;
		while (lo + 1 < hi) {
			int mid = (hi + lo) / 2;
			ll w = calc(mid);
			if (w == -1)
				hi = mid;
			else
				lo = mid;
		}
		ll w = calc(lo);
// cerr << " -> " << lo << ' ' << w << endl;
		res = max(res, make_tuple(w * cm + i * cf, lo, w, i));
		if (i != N) {
			m -= A - a[N-1 - i];
			a[N-1 - i] = A;
			if (m < 0) break;
		}
	}
	}

	int lo = get<1>(res);
	ll w = get<2>(res);
	int nummax = get<3>(res);
// cerr << "DBG " << lo << ' ' << w << ' ' << nummax << endl;
	rep(i,0,nummax)
		origA[N-1-i].first = A;
	rep(i,0,lo)
		origA[i].first = w;
	sort(all(origA), [](pair<ll, int> a, pair<ll, int> b) { return a.second < b.second; });
	cout << get<0>(res) << endl;
	rep(i,0,N)
		cout << origA[i].first << ' ';
	cout << endl;
}