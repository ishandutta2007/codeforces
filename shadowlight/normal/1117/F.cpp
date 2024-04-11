#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <vector <int> > pref;
int n, p;

int calc_mask(int l, int r) {
	int mask = 0;
	for (int i = 0; i < p; i++) {
		if ((pref[r + 1][i] - pref[l][i])) {
			mask += (1 << i);
		}
	}
	return mask;
}

void print(int x) {
	for (int i = 0; i < p; i++) {
		cout << (x & (1 << i) ? 1 : 0);
	}
	cout << "\n";
}

int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> p;
	string s;
	cin >> s;
	vector <vector <int> > pos(p);
	pref.resize(n + 1, vector <int> (p, 0));
	vector <int> cnt(p, 0);
	int smask = 0;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
		pos[s[i] - 'a'].push_back(i);
		smask |= 1 << (s[i] - 'a');
		pref[i + 1] = pref[i];
		pref[i + 1][s[i] - 'a']++;
	}
	int N = 1 << p;
	vector <bool> canbe(N, false);
	vector <vector <int> > masks(p, vector <int> (N, 0));
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			int ni = 0, nj = 0;
			while (ni < pos[i].size() && nj < pos[j].size()) {
				int l = pos[i][ni], r = pos[j][nj];
				if (l == r) {
					nj++;
					continue;
				}
				if (l > r) {
					nj++;
					swap(l, r);
				} else {
					ni++;
				}
				int mask = calc_mask(l + 1, r - 1);
				if (mask & (1 << i) || mask & (1 << j)) {
					continue;
				}
				masks[i][mask] |= (1 << j);
				masks[j][mask] |= (1 << i);
			}
		}
	}
	for (int mask = 0; mask < N; mask++) {
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) {
				masks[i][mask | (1 << j)] |= masks[i][mask];
				if (masks[i][mask | (1 << j)] & (1 << j)) {
					masks[i][mask | (1 << j)] ^= (1 << j);
				}
			}
		}
	}
	vector <int> forb(p, 0);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			int x;
			cin >> x;
			if (!x) {
				forb[i] |= (1 << j);
			}
		}
	}
	canbe[smask] = true;
	int sum = n;
	for (int mask = N - 1; mask >= 0; mask--) {
		for (int i = 0; i < p; i++) {
			if (mask & (1 << i)) continue;
			int mask1 = mask | (1 << i);
			if (!canbe[mask1]) continue;
			bool can = true;
			for (int j = 0; j < p; j++) {
				if (!(mask & (1 << j))) continue;
				int m = masks[j][(N - 1) ^ mask];
				if (m & forb[j]) {
					can = false;
					break;
				}
			}
			if (can) {
				canbe[mask] = true;
				break;
			}
		}
		if (canbe[mask]) {
			//print(mask);
			int now = 0;
			for (int i = 0; i < p; i++) {
				if (mask & (1 << i)) {
					now += cnt[i];
				}
			}
			sum = min(sum, now);
		}
	}
	cout << sum << "\n";
}