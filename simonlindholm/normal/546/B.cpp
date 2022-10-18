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
	int N;
	cin >> N;
	vi v(N);
	trav(x,v) cin >> x;
	sort(all(v));
	int last = 0;
	ll cost = 0;
	trav(x, v) {
		last = max(last + 1, x);
		cost += last - x;
	}
	cout << cost << endl;
}