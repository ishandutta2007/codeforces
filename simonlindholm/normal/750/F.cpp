#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vi> mem;
int qrem;
vi query(int x) {
	if (mem.count(x)) return mem.at(x);
	if (qrem == 0) throw x;
	cout << "? " << x << endl;
	--qrem;
	int k;
	cin >> k;
	vi v(k);
	rep(i,0,k) cin >> v[i];
	if (k == 2) throw x;
	mem[x] = v;
	return v;
}

void dfs(int at, int par, vi& path) {
	path.push_back(at);
	vi v = query(at);
	trav(x, v) if (x != par) {
		dfs(x, at, path);
		break;
	}
}

void solve(int h) {
	vi v = query(1);
	vi path1, path2;
	dfs(v[0], 1, path1);
	if (sz(v) > 1) dfs(v[1], 1, path2);
	vi path;
	path.insert(path.end(), path2.rbegin(), path2.rend());
	path.push_back(1);
	path.insert(path.end(), path1.begin(), path1.end());
	assert(sz(path) % 2 == 1);

	int mid = path[sz(path)/2];
	int up = -1;
	trav(x, query(mid)) if (!mem.count(x)) {
		up = x;
		break;
	}

	for (;;) {
		if (sz(path) >= 7) {
			trav(x, query(up)) if (!mem.count(x)) {
				trav(y, query(x)) if (!mem.count(y)) {
					query(y);
				}
			}
			assert(false);
		}

		vi path3(path.begin(), path.begin() + (sz(path)/2 + 1));
		dfs(up, mid, path3);
		path = move(path3);
		mid = path[sz(path)/2];
		up = -1;
		trav(x, query(mid)) if (!mem.count(x)) {
			up = x;
			break;
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	rep(i,0,N) {
		int h;
		cin >> h;
		mem.clear();
		qrem = 16;
		try {
			solve(h);
		} catch(int x) {
			cout << "! " << x << endl;
		}
	}
	exit(0);
}