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
	vi v;
	vector<pii> und;
	vector<pair<int, set<int>>> und2;
	vector<set<int>> essense;
	UF(int n) : v(n, -1), essense(n) {}
	int find(int x) {
		if (v[x] < 0) return x;
		if (v[v[x]] < 0) return v[x];
		int r = find(v[x]);
		und.emplace_back(x, v[x]);
		v[x] = r;
		return r;
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (-v[a] < -v[b]) swap(a, b);
		und2.emplace_back(a, essense[a]);
		und.emplace_back(a, v[a]);
		und.emplace_back(b, v[b]);
		essense[a].insert(all(essense[b]));
		v[a] = v[a] + v[b];
		v[b] = a;
	}
	void undo() {
		while (!und.empty()) {
			auto pa = und.back();
			v[pa.first] = pa.second;
			und.pop_back();
		}
		while (!und2.empty()) {
			auto pa = und2.back();
			essense[pa.first] = move(pa.second);
			und2.pop_back();
		}
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int H, W, Q;
	cin >> H >> W >> Q;
	vector<string> board(H+2);
	rep(i,0,H) cin >> board[i+1], board[i+1] = '#' + board[i+1] + '#';
	board[0] = board.back() = string(W+2, '#');

	UF uf((H+2) * (W+2));
	auto code = [&](int i, int j) {
		return i * (W+2) + j;
	};
	int bottomleft = code(H+1, 0);
	int topright = code(0, W+1);
	auto good = [&](int i, int j) {
		if (i < 0 || j < 0 || i >= H+2 || j >= W+2) return false;
		if (i <= 1 && j <= 1) return false;
		if (i >= H && j >= W) return false;
		return true;
	};
	auto goodmove = [&](int i, int j, int i2, int j2) {
		if (((i - i2) & 2) && ((j - j2) & 2) && !good((i+i2)>>1, (j+j2)>>1))
			return false;
		return true;
	};

	rep(i,0,H+2) rep(j,0,W+2) if (good(i,j) && board[i][j] == '#') {
		rep(di,-1,2) rep(dj,-1,2) if (di || dj) {
			int ni = i + di, nj = j + dj;
			if (good(ni, nj) && board[ni][nj] == '#') {
				uf.join(code(i, j), code(ni,nj));
			}
		}
	}
	uf.und.clear();
	uf.und2.clear();

	set<pii> ed;
	rep(i,0,H+2) rep(j,0,W+2) if (good(i,j) && board[i][j] == '#') {
		rep(di,-2,3) rep(dj,-2,3) if (di || dj) {
			int ni = i + di, nj = j + dj;
			if (good(ni, nj) && goodmove(i, j, ni, nj) && board[ni][nj] == '#') {
				ed.insert(pii(uf.find(code(i,j)), uf.find(code(ni,nj))));
			}
		}
	}
	rep(i,0,H+2) rep(j,0,W+2) if (good(i,j) && board[i][j] == '#') {
		int c = code(i,j);
		if (uf.find(c) == c) uf.essense[c].insert(c);
	}

	auto query = [&](const vector<pii>& ca) -> bool {
		bool ret = false;
		{
		trav(pa, ca) {
			int i,j;
			tie(i,j) = pa;
			board[i][j] = '#';
		}
		trav(pa, ca) {
			int i,j;
			tie(i,j) = pa;
			rep(di,-1,2) rep(dj,-1,2) if (di || dj) {
				int ni = i + di, nj = j + dj;
				if (good(ni, nj) && board[ni][nj] == '#') {
					uf.join(code(i, j), code(ni, nj));
				}
			}
		}
		int A = uf.find(bottomleft);
		int B = uf.find(topright);
		// cerr << A << ' ' << B << endl;
		if (A == B) goto fail;
		// trav(x, uf.essense[A]) cerr << x << ' '; cerr << endl;
		// trav(x, uf.essense[B]) cerr << x << ' '; cerr << endl;
		trav(x, uf.essense[A]) trav(y, uf.essense[B]) {
			if (ed.count(pii(x,y))) goto fail;
		}
		trav(pa, ca) {
			int i,j;
			tie(i,j) = pa;
			int p = uf.find(code(i,j));
			rep(di,-2,3) rep(dj,-2,3) if (di || dj) {
				int ni = i + di, nj = j + dj;
				// if (ni == 3 && nj == 3)
					// cerr << "G " << good(ni,nj) << ' ' << goodmove(i,j,ni,nj) << ' ' << board[ni][nj] << endl;
				if (good(ni, nj) && goodmove(i, j, ni, nj) && board[ni][nj] == '#') {
					int q = uf.find(code(ni,nj));
					// cerr << ' ' << i << ' ' << j << ' ' << ni << ' ' << nj << ' ' << p << ' ' << q << endl;
					if (p == A && q == B) goto fail;
					if (p == B && q == A) goto fail;
				}
			}
		}

		ret = true;
		}
fail:
		trav(pa, ca) {
			int i,j;
			tie(i,j) = pa;
			board[i][j] = '.';
		}
		uf.undo();
		return ret;
	};

	rep(qi,0,Q) {
		int K;
		cin >> K;
		vector<pii> ca;
		rep(i,0,K) {
			int r, c;
			cin >> r >> c;
			ca.emplace_back(r,c);
		}
		cout << (query(ca) ? "YES" : "NO") << endl;
	}
	exit(0);
}