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
	int N, S1, S2;
	cin >> N >> S1 >> S2;
	vi pos(N);
	rep(i,0,N) cin >> pos[i];
	auto works = [&](int maxdist) {
		if (abs(S1 - S2) > maxdist) return false;
		set<int> aset, bset;
		aset.insert(S1);
		bset.insert(S2);
		rep(i,0,N) {
			int p = pos[i];
			int lasta = (i == 0 ? S1 : pos[i-1]);
			int lastb = (i == 0 ? S2 : pos[i-1]);

			// set<int> naset, nbset;

			bool addlasta = false;
			bool addlastb = false;
			if (!aset.empty() && abs(lastb - p) <= maxdist)
				addlastb = true;
			if (!bset.empty() && abs(lasta - p) <= maxdist)
				addlasta = true;

			while (!bset.empty() && abs(*bset.begin() - p) > maxdist) bset.erase(bset.begin());
			while (!aset.empty() && abs(*aset.begin() - p) > maxdist) aset.erase(aset.begin());
			while (!bset.empty() && abs(*bset.rbegin() - p) > maxdist) bset.erase(--bset.end());
			while (!aset.empty() && abs(*aset.rbegin() - p) > maxdist) aset.erase(--aset.end());

			/*
			trav(x, bset) {
				if (abs(x - p) <= maxdist) nbset.insert(x);
			}
			trav(x, aset) {
				if (abs(x - p) <= maxdist) naset.insert(x);
			}
			*/

			// aset = naset;
			// bset = nbset;

			if (addlastb)
				bset.insert(lastb);
			if (addlasta)
				aset.insert(lasta);

			if (aset.empty() && bset.empty()) return false;
		}
		return !aset.empty() || !bset.empty();
	};
	int lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		int mid = lo + (hi - lo) / 2;
		if (works(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
	exit(0);
}