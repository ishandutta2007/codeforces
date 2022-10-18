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
	int N;
	cin >> N;
	// h(g(x)) = f(x), x = 1..n
	// g(h(x)) = x, x = 1..m
	// g(h(g(x))) = g(f(x)) = g(x)
	// h(g(h(x))) = f(h(x)) = h(x)
	// f(f(x)) = f(x)
	// h: m -> n "blowup", g: n -> m, "reduce"
	// g injective -> m <= n
	// h surjective -> |im(f)|
	vi f(N);
	rep(i,0,N) cin >> f[i], f[i]--;
	rep(i,0,N) if (f[f[i]] != f[i]) {
		cout << -1 << endl;
		exit(0);
	}
	map<int, int> s;
	rep(i,0,N) s[f[i]];
	int count = 0;
	trav(pa, s) pa.second = count++;
	int m = count;

	cout << m << endl;
	rep(i,0,N) cout << s[f[i]]+1 << ' ';
	cout << endl;
	trav(pa, s) cout << pa.first+1 << ' ';
	cout << endl;
	exit(0);
}