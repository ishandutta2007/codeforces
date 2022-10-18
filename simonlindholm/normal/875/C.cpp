#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = (f >= 0 ? 2*f : -1-2*f);
		j = (j >= 0 ? 2*j : -1-2*j);
		gr[f^1].push_back(j);
		gr[j^1].push_back(f);
	}
	void set_value(int x) { either(x, x); }

	void at_most_one(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = add_var();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = !(x&1);
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<vi> seqs(N);
	rep(i,0,N) {
		int L;
		cin >> L;
		vi seq(L);
		rep(j,0,L) cin >> seq[j], --seq[j];
		seqs[i] = move(seq);
	}

	TwoSat ts(M);
	rep(i,0,N-1) {
		int l = min(sz(seqs[i]), sz(seqs[i+1]));
		int same = 0;
		rep(j,0,l) {
			if (seqs[i][j] == seqs[i+1][j]) same++;
			else break;
		}
		if (same == l) {
			if (same == sz(seqs[i])) continue; // then it's fine
			cout << "No" << endl;
			exit(0);
		}
		int a = seqs[i][same];
		int b = seqs[i+1][same];
		if (a < b) {
			ts.either(a, ~b);
		} else {
			ts.set_value(a);
			ts.set_value(~b);
		}
	}

	bool b = ts.solve();
	if (!b) {
		cout << "No" << endl;
	} else {
		vi res;
		rep(i,0,M) if (ts.values[i]) res.push_back(i+1);
		cout << "Yes" << endl;
		cout << sz(res) << endl;
		trav(x, res) cout << x << ' ';
		cout << endl;
	}
	exit(0);
}