#include <bits/stdc++.h>
using namespace std;

const vector<char> DNA = {
'A',
'N',
'O',
'T'
};

void solve() {
	string raw_dna;
	cin >> raw_dna;
	int n = raw_dna.size();
	vector<int> dna(n);
	for (int i = 0; i < n; ++i) {
		dna[i] = find(DNA.begin(), DNA.end(), raw_dna[i]) - DNA.begin();
	}
	vector<int> cnt(4, 0);
	for (int x : dna) {
		++cnt[x];
	}
	vector<int> p(4);
	for (int i = 0; i < 4; ++i) {
		p[i] = i;
	}
	vector<int> best;
	long long best_cost = -1;
	do {
		vector<int> inverse_p(4);
		for (int i = 0; i < 4; ++i) {
			inverse_p[p[i]] = i;
		}
		vector<int> target;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < cnt[p[i]]; ++j) {
				target.push_back(p[i]);
			}
		}
		long long cur_cost = 0;
		vector<int> cur_cnt(4, 0);
		for (int i = 0; i < n; ++i) {
			int inv = inverse_p[dna[i]];
			for (int j = inv + 1; j < 4; ++j) {
				cur_cost += cur_cnt[j];
			}
			++cur_cnt[inv];
		}
		if (cur_cost > best_cost) {
			best_cost = cur_cost;
			best = target;
		}
	} while (next_permutation(p.begin(), p.end()));
	string raw_target = "";
	for (int i = 0; i < n; ++i) {
		raw_target.push_back(DNA[best[i]]);
	}
	// cerr << "result: " << raw_target << ", cost: " << best_cost << '\n';
	cout << raw_target << '\n';
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}