#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<pair<pii,int>> vpii;

template<class F, class T>
void rec(int from, int to, F f, vpii& ret, int& i, T& p, T q) {
	if (p == q) return;
	if (from == to) {
		ret.emplace_back(pii(i, to), p);
		i = to; p = q;
	} else {
		int mid = (from + to) >> 1;
		rec(from, mid, f, ret, i, p, f(mid));
		rec(mid+1, to, f, ret, i, p, q);
	}
}
template<class F>
vpii constantIntervals(int from, int to, F f) {
	vpii ret;
	if (to <= from) return ret;
	int i = from; auto p = f(i), q = f(to-1);
	rec(from, to-1, f, ret, i, p, q);
	ret.emplace_back(pii(i, to), q);
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi col(N);
	rep(i,0,N) cin >> col[i], col[i]--;
	vi used(N), vused;
	auto v = constantIntervals(1, N+1, [&](int k) {
		int res = 0, u = 0;
		int lasti = -1;
		rep(i,0,N) {
			if (!used[col[i]]++) {
				if (u == k) {
					u = 0;
					trav(c, vused) used[c] = 0;
					vused.clear();
					res++;
					lasti = i;
				}
				vused.push_back(col[i]);
				u++;
			}
		}
		trav(c, vused) used[c] = 0;
		vused.clear();
		return res + 1;
	});
	vi res(N);
	trav(x, v) {
		rep(i,x.first.first,x.first.second) res[i-1] = x.second;
	}
	rep(i,0,N) cout << res[i] << ' ';
	cout << endl;
	exit(0);
}