#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
set<pii> zs;
int in;
void remo(int l, int r) {
	if (zs.size() == 0) return;
	pii tempo = pii(l, l-1);
	set<pii>::iterator it = zs.lower_bound(tempo);
	if (it != zs.begin()) --it;
	// --it;
	while (1) {
		if (it == zs.end()) break;
		pii tp = *it;
		// cout << "cur   " << tp.first << ", " << tp.second << endl;
		if (tp.first > r) break;
		if (tp.first >= l && tp.second <= r) {
			in -= (tp.second-tp.first+1);
			it = zs.erase(it);
		}
		else if (tp.first >= l && tp.first <= r && tp.second > r) {
			it = zs.erase(it);
			in -= r-tp.first+1;
			zs.insert(pii(r+1, tp.second));
		}
		else if (tp.first < l && tp.second >= l && tp.second <= r) {
			it = zs.erase(it);
			in -= tp.second-l+1;
			zs.insert(pii(tp.first, l-1));
		}
		else if (l >= tp.first && r <= tp.second) {
			it = zs.erase(it);
			in -= r-l+1;
			zs.insert(pii(tp.first, l-1));
			zs.insert(pii(r+1, tp.second));
			return;
		}
		else ++it;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	
	cin >> n >> q;
	int l, r, k;
	in = 0;
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> k;
		if (k == 2) {
			remo(l, r);

		} 
		else {
			remo(l, r);
			zs.insert(pii(l, r));
			in += r-l+1;
		}
		cout << n-in << endl;
		// for (set<pii>::iterator it2 = zs.begin();
		// 	it2 != zs.end(); ++it2) {
		// 	cout << (*it2).first << "," << (*it2).second << " ";
		// }
		// cout << "end" << endl << endl;
	}
	cin >> n;
}