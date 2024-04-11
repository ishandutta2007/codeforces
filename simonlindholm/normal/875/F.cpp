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
	vi e, si;
	UF(int n) : e(n, -1), si(n, 0) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	bool full(int x) {
		x = find(x);
		return si[x] == -e[x];
	}
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) {
			++si[a];
			return;
		}
		if (e[a] > e[b]) swap(a, b);
		si[a] += si[b] + 1;
		e[a] += e[b]; e[b] = a;
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, int>> pr;
	pr.reserve(M);
	rep(i,0,M) {
		int a, b, w;
		cin >> a >> b >> w;
		--a, --b;
		pr.emplace_back(-w, a, b);
	}
	sort(all(pr));

	UF uf(N);

	ll res = 0;
	auto add = [&](int a, int b) {
		a = uf.find(a);
		b = uf.find(b);
		if (uf.full(a) && uf.full(b)) return false;
		uf.join(a, b);
		return true;
	};
	trav(pa, pr) {
		int w, a, b;
		tie(w, a, b) = pa;
		w = -w;
		if (add(a, b)) res += w;
	}
	cout << res << endl;
	exit(0);
}