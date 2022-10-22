#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <int> p, r;

int get(int v) {
	return (v == p[v] ? v : p[v] = get(p[v]));
}

bool uni(int v, int u) {
	v = get(v);
	u = get(u);
	if (v == u) return true;
	if (r[v] == r[u]) r[u]++;
	if (r[v] > r[u]) swap(v, u);
	p[v] = u;
	return false;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	p.resize(n);
	r.resize(n);
	int res = 0;
	iota(p.begin(), p.end(), 0);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (uni(a, b)) {
			res++;
		}
	}
	cout << res << "\n";

}