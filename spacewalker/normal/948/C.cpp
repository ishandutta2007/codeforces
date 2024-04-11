#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

class partsum {
	vector<ll> part;
	int n;
public:
	partsum(vector<ll> orig) : n(orig.size()), part(orig.size() + 1, 0) {
		for (int i = 0; i < n; ++i) {
			part[i + 1] = part[i] + orig[i];
		}
	}
	ll query(int i, int j) {
		return part[j+1] - part[i];
	}
};

class compiledrangeup {
	vector<ll> tocomp;
	int n;
public:
	compiledrangeup(int ct) : tocomp(ct + 1, 0), n(ct) {};
	void add(int i, int j) {
		++tocomp[i];
		--tocomp[j+1];
	}
	vector<ll> compile() {
		vector<ll> ans(n, tocomp[0]);
		//cout << "tc[0] = " << tocomp[0] << endl;
		for (int i = 1; i < n; ++i) {
			//cout << "tc[" << i << "] = " << tocomp[i] << endl;
			ans[i] = ans[i-1] + tocomp[i];
			//cout << "ans = " << ans[i] << endl;
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<ll> piles(n, 0);
	vector<ll> temps(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> piles[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> temps[i];
	}
	partsum olaf(temps);
	compiledrangeup survived(n);
	vector<ll> atDeath(n, 0);
	for (int i = 0; i < n; ++i) {
		//cout << "calcing " << i << endl;
		if (olaf.query(i, n - 1) <= piles[i]) {
			//cout << "skip called; adding " << i << " to " << n - 1 << endl;
			survived.add(i, n - 1);
			continue;
		}
		// find the first k such that t_i + t_(i+1) + ... + t_k > p_i
		// binary search!
		int lo = i;
		int hi = n - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (olaf.query(i, mid) > piles[i]) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		if (lo == i) {
			// this pile won't even survive the day.
			atDeath[i] += piles[i];
			//cout << "pile amount added to day's kill count" << endl;
			continue;
		}
		// because we guaranteed that the pile dies before the problem ends
		survived.add(i, lo - 1);
		atDeath[lo] += (piles[i] - olaf.query(i, lo - 1));
		//cout << "added to " << i << " to " << lo - 1 << endl;
		//cout << "dadd of " << (piles[i] - olaf.query(i, lo - 1)) << " to " << lo << endl;
	}
	vector<ll> killCount = survived.compile();
	for (int i = 0; i < n; ++i) {
		//cout << "kc[" << i << "] and ad = " << killCount[i] << " " << atDeath[i] << endl;
		cout << (i == 0 ? "" : " ") << (temps[i] * killCount[i]) + atDeath[i];
	}
	cout << endl;
	return 0;
}