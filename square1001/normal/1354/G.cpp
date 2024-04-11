#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
mt19937 mt(2005171937);
int rand_rng(int l, int r) {
	uniform_int_distribution<int> p(l, r - 1);
	return p(mt);
}
vector<int> choose(int N, int K) {
	vector<bool> used(N, false);
	vector<int> seq;
	for (int i = 0; i < K; ++i) {
		int p = -1;
		while (p == -1 || used[p]) {
			p = rand_rng(0, N);
		}
		used[p] = true;
		seq.push_back(p);
	}
	sort(seq.begin(), seq.end());
	return seq;
}
bool debug = false;
vector<int> hidden;
int min_index;
void gen_array(int N, int K) {
	vector<int> g = choose(N, K);
	hidden.resize(N);
	for (int i = 0; i < N; ++i) {
		if (binary_search(g.begin(), g.end(), i)) {
			hidden[i] = rand_rng(1, 100);
		}
		else {
			hidden[i] = 100;
		}
	}
	min_index = g[0];
}
string ask(vector<int> a, vector<int> b) {
	cout << "? " << a.size() << ' ' << b.size() << endl;
	for (int i = 0; i < a.size(); ++i) {
		if (i) cout << ' ';
		cout << a[i] + 1;
	}
	cout << endl;
	for (int i = 0; i < b.size(); ++i) {
		if (i) cout << ' ';
		cout << b[i] + 1;
	}
	cout << endl;
	string res;
	if (!debug) {
		cin >> res;
	}
	else {
		int sa = 0, sb = 0;
		for (int i : a) sa += hidden[i];
		for (int i : b) sb += hidden[i];
		if (sa > sb) res = "FIRST";
		if (sa < sb) res = "SECOND";
		if (sa == sb) res = "EQUAL";
	}
	return res;
}
void answer(int x) {
	cout << "! " << x + 1 << endl;
	if (debug) {
		assert(x == min_index);
	}
}
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		int N, K;
		if (!debug) {
			cin >> N >> K;
		}
		else {
			N = 4, K = 1;
			gen_array(N, K);
		}
		if (N <= 4) {
			int curmax = 0;
			for (int i = 1; i < N; ++i) {
				string res = ask({ curmax }, { i });
				if (res == "SECOND") curmax = i;
			}
			int ans = -1;
			for (int i = 0; i < N; ++i) {
				if (i != curmax) {
					string res = ask({ curmax }, { i });
					if (res == "FIRST") {
						ans = i;
						break;
					}
				}
			}
			answer(ans);
		}
		else {
			// step #1. find one stone (fail probability <= (1/2)^threshold)
			const int threshold = 23;
			vector<int> g = choose(N - 2, min(N - 2, threshold));
			for (int i = 0; i < g.size(); ++i) {
				g[i] += 2;
			}
			int stone = g[0];
			for (int i = 1; i < g.size(); ++i) {
				string res = ask({ stone }, { g[i] });
				if (res == "SECOND") {
					stone = g[i];
				}
			}
			string resp0 = ask({ stone }, { 0 });
			string resp1 = ask({ stone }, { 1 });
			if (resp0 == "FIRST") {
				answer(0);
			}
			else if (resp1 == "FIRST") {
				answer(1);
			}
			else {
				int t = 2;
				while (t * 2 <= N) {
					vector<int> lc(t), rc(t);
					for (int i = 0; i < t; ++i) {
						lc[i] = i;
						rc[i] = i + t;
					}
					string res = ask(lc, rc);
					if (res != "EQUAL") {
						break;
					}
					t *= 2;
				}
				int lp = t, rp = min(2 * t, N);
				while (rp - lp > 1) {
					int m = (lp + rp) >> 1;
					vector<int> lc(m - t), rc(m - t);
					for (int i = 0; i < m - t; ++i) {
						lc[i] = i;
						rc[i] = i + t;
					}
					string res = ask(lc, rc);
					if (res != "EQUAL") {
						rp = m;
					}
					else {
						lp = m;
					}
				}
				answer(lp);
			}
		}
	}
	return 0;
}