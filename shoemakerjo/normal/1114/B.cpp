#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<ll, int>;

const int maxn = 200010;
int n, m, k;

bool isin[maxn];
ll ans;
ll nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	ans = 0LL;

	vector<pli> vals;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		vals.push_back(pli(nums[i], i));
	}
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());
	for (int i = 0; i < m*k; i++) {
		ans += vals[i].first;
		isin[vals[i].second] = true;
	}

	cout << ans << endl;
	int ct = 0;
	int totct = 0;
	for (int i = 1; i <= n; i++) {
		if (isin[i]) {
			ct++;
			totct++;
			if (ct == m) {
				if (totct != m*k) {
					cout << i << " ";
				}
				ct = 0;
			}
		}
	}
	cout << endl;

}