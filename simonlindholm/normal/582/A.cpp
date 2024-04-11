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
	multiset<int, greater<int> > ms;
	rep(i,0,N*N) {
		int a;
		cin >> a;
		ms.insert(a);
	}
	vi vals;
	while (!ms.empty()) {
		int n = *ms.begin();
		cout << n << ' ';
		trav(m, vals) {
			int g = __gcd(n, m);
			auto it = ms.find(g);
			ms.erase(it);
			it = ms.find(g);
			ms.erase(it);
		}
		vals.push_back(n);
		auto it = ms.find(n);
		ms.erase(it);
	}
	cout << endl;
}