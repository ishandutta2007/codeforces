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
	cin.tie(0);
	int N;
	cin >> N;
	vi price(N);
	set<int> avail;
	rep(i,0,N) {
		cin >> price[i];
		avail.insert(price[i]);
	}
	set<int> ts[3];
	rep(i,0,N) {
		int c;
		cin >> c;
		ts[c-1].insert(price[i]);
	}
	rep(i,0,N) {
		int c;
		cin >> c;
		ts[c-1].insert(price[i]);
	}

	int M;
	cin >> M;
	rep(i,0,M) {
		int c;
		cin >> c;
		--c;
		while (!ts[c].empty()) {
			int v = *ts[c].begin();
			ts[c].erase(ts[c].begin());
			if (!avail.count(v)) continue;
			avail.erase(v);
			cout << v << ' ';
			goto next;
		}
		cout << -1 << ' ';
next:;
	}
	cout << endl;

	exit(0);
}