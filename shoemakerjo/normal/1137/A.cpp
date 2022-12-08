#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
const int maxn = 1010;
int n, m;

int nums[maxn][maxn];

int rval[maxn][maxn];
int cval[maxn][maxn];

int rmax[maxn];
int cmax[maxn]; //column max



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		vector<pii> vals;
		for (int j = 0; j < m; j++) {
			vals.push_back(pii(nums[i][j], j));
		}
		sort(vals.begin(), vals.end());

		int cur = 0;

		for (int j = 0; j < vals.size(); j++) {
			if (j == 0 || vals[j].first != vals[j-1].first) ++cur;

			rval[i][vals[j].second] = cur;
			rmax[i] = cur;
		}
	}

	for (int i = 0; i < m; i++) {
		vector<pii> vals;
		for (int j = 0; j < n; j++) {
			vals.push_back(pii(nums[j][i], j));
		}
		sort(vals.begin(), vals.end());
		int cur = 0;

		for (int j = 0; j < vals.size(); j++) {
			if (j == 0 || vals[j].first != vals[j-1].first) ++cur;

			cval[vals[j].second][i] = cur;
			cmax[i] = cur;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cv = max(rval[i][j], cval[i][j]);

			cv += max(rmax[i] - rval[i][j], cmax[j] - cval[i][j]);

			cout << cv << " ";
		}
		cout << '\n';
	}
	cout.flush();

}