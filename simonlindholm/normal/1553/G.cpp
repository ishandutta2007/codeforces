#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	vi factor(1'000'002);
	for (ll i = 2; i <= 1'000'001; i++) if (factor[i] == 0) {
		factor[i] = (int)i;
		for (ll j = i*i; j <= 1'000'001; j += i) {
			factor[j] = (int)i;
		}
	}

	int N, Q;
	cin >> N >> Q;
	vi pr(N);
	UF uf(1'000'002);
	vector<pii> ed2;
	rep(i,0,N) {
		int x;
		cin >> x;
		int origx = x;
		int last = 0;
		while (factor[x]) {
			if (last) uf.join(last, factor[x]);
			last = factor[x];
			x /= last;
		}
		pr[i] = last;

		x = origx + 1;
		vi ed;
		while (factor[x]) {
			ed.push_back(factor[x]);
			x /= factor[x];
		}
		trav(p,ed) trav(q,ed) {
			ed2.push_back({p, q});
		}
		trav(p,ed) {
			ed2.push_back({p, last});
			ed2.push_back({last, p});
		}
	}

	set<pii> edset;
	trav(pa, ed2) {
		int a = uf.find(pa.first);
		int b = uf.find(pa.second);
		if (a != b) edset.insert({a,b});
	}

	rep(qi,0,Q) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		a = uf.find(pr[a]);
		b = uf.find(pr[b]);
		if (a == b) cout << "0\n";
		else if (edset.count({a,b})) cout << "1\n";
		else cout << "2\n";
	}

	cout << flush;
	exit(0);
}