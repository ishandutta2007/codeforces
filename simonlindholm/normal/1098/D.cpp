#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int Q;
	cin >> Q;
	map<int, int> addCounts, delCounts;
	map<pii, int> ren;
	vector<tuple<char, int, int>> ops;
	rep(qi,0,Q) {
		char type;
		int w;
		cin >> type >> w;
		int w2;
		if (type == '+') {
			w2 = addCounts[w]++;
			ren[make_pair(w, w2)];
		}
		else {
			w2 = delCounts[w]++;
			ren[make_pair(w, w2)];
		}
		ops.emplace_back(type, w, w2);
	}
	int ind = 0;
	trav(pa, ren) pa.second = ind++;

	int N = ind;
	FT fw(N);

	map<int, int> cands; // index -> weight
	map<int, int> aquarium; // index -> weight

	trav(op, ops) {
		int w = get<1>(op);
		int index = ren[pii(w, get<2>(op))];
		char t = get<0>(op);

		if (t == '+') {
			auto it = cands.lower_bound(index);
			if (it != cands.end() && it->second <= 2*w)
				cands.erase(it);
			auto it2 = aquarium.lower_bound(index);
			if (it2 != aquarium.begin()) {
				it2--;
				if (it2->second * 2 < w) cands.emplace(index, w);
			}
			else {
				cands.emplace(index, w);
			}
			aquarium[index] = w;
			fw.update(index, w);
		}
		else {
			aquarium.erase(index);
			cands.erase(index);
			fw.update(index, -w);
			auto it = aquarium.lower_bound(index);
			if (it != aquarium.end()) {
				int index2 = it->first;
				int w2 = it->second;
				if (it == aquarium.begin()) {
					if (!cands.count(index2)) {
						cands.insert(*it);
					}
				} else {
					if (!cands.count(index2)) {
						auto before = it;
						--before;
						if (before->second * 2 < w2) {
							cands.insert(*it);
						}
					}
				}
			}
		}

		/*
		cout << t << ' ' << index << ' ' << w << endl;
		cout << "Aquarium:" << endl;
		trav(pa, aquarium) cout << pa.first << ' ' << pa.second << endl;
		cout << "Cands:" << endl;
		trav(pa, cands) cout << pa.first << ' ' << pa.second << endl;
		cout << endl;
		*/

		if (aquarium.empty()) {
			cout << 0 << '\n';
		} else {
			int r = sz(aquarium) - 1;
			trav(pa, cands) {
				ll sum = fw.query(pa.first);
				if (sum && sum * 2 < pa.second) {
					r--;
				}
			}
			cout << r << '\n';
		}
	}

	exit(0);
}