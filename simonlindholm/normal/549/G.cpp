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
	map<int, int> m;
	vector<int> a(N);
	rep(i,0,N) {
		cin >> a[i], a[i] += i;
		if (m[a[i]]++) {
			cout << ":(" << endl;
			return 0;
		}
	}
	map<int, int> nem;
	int ind = 0;
	trav(pa, m)
		nem[pa.first] = ind++;
	vi s;
	rep(i,0,N) {
		s.push_back(a[i] - nem[a[i]]);
	}
	sort(all(s));
	trav(x, s) cout << x << ' ';
	cout << endl;
}