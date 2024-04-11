#include <bits/stdc++.h>

using namespace std;
#define maxn 1510
#define pii pair<int, int>
int n, s, m, k;

int nums[maxn];
int l[maxn];
int r[maxn];
int pref[maxn];
vector<pii> iv;

vector<int> stopoverlap[maxn];

int lc, rc;
int nonoverlap[maxn]; //indexed based on number used
deque<int> overlap[maxn]; //indexed based on number used

int myval[maxn][maxn];
int iter = 0;

bool go(int mid) {
	iter++;
	int ans = 0;
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1];
		if (nums[i] <= mid) pref[i]++;
	}
	fill(nonoverlap, nonoverlap+maxn, 0);
	for (int i = 0; i <= n; i++) {
		overlap[i].clear();
	}
	
	for (int i = 0; i < iv.size(); i++) {
		rc = iv[i].second;
		lc = iv[i].first;
		// if (iter <= 2) cout << "interval: " << i << " : " << lc << " - " << rc << endl;

		for (int v : stopoverlap[i]) {

			for (int j = 0; j <= m; j++) {
				int cur = myval[v][j] - pref[iv[v].second];
				if (overlap[j].front() == cur) {
					overlap[j].pop_front();
				}
				nonoverlap[j] = max(nonoverlap[j], myval[v][j]);
			}
		}

		for (int j = 1; j <= m; j++) {
			//calculate this ans
			myval[i][j] = nonoverlap[j-1] + pref[rc]-pref[lc-1];
			if (overlap[j-1].size()) {
				myval[i][j] = max(myval[i][j],
				overlap[j-1].front() + pref[rc]);
			}
			ans = max(ans, myval[i][j]);
			// if (iter <= 2) cout << "value: " << i << " " << j << " ::   " << myval[i][j] << endl;

			int cur = myval[i][j] - pref[rc];
			while (overlap[j].size() && overlap[j].back() < cur) {
				overlap[j].pop_back();
			}
			overlap[j].push_back(cur);

		}
	}


	return ans >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s >> m >> k;
	vector<int> lens;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < s; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < s; i++) {
		bool ok = true;
		for (int j = 0; j < s; j++) {
			if (l[j] <= l[i] && r[i] <= r[j]) {
				if (l[j] == l[i] && r[i] == r[j]) {
					if (j <= i) continue;
				}
				ok = false;
				break;
			}
		}
		if (ok) iv.push_back(pii(l[i], r[i]));
	}
	sort(iv.begin(), iv.end());
	for (int i = 0; i < iv.size(); i++) {
		for (int j = i+1; j < iv.size(); j++) {
			if (iv[i].second < iv[j].first) {
				stopoverlap[j].push_back(i);
				break;
			}
		}
	}

	int lo = 1;
	int hi = 1000000000;
	vector<int> cvals;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (go(mid)) {
			hi = mid;
		}
		else lo = mid+1;
	}
	if (!go(lo)) {
		cout << -1 << endl;
		return 0;
	}
	cout << lo << endl;


}