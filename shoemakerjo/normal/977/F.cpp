#include <bits/stdc++.h>

using namespace std;

#define maxn 200010

int pr[maxn]; 
int lcs[maxn];
int nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	map<int, int> rec; //most recent occurrence of a value
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int ans = 0;
	int spot = 0;
	for (int i = 1; i <= n; i++) {
		rec[nums[i]] = i;
		if (rec.find(nums[i]-1) == rec.end()) {
			lcs[i] = 1;
			pr[i] = -1;
			if (lcs[i] > ans) {
				ans = lcs[i];
				spot = i;
			}
			continue;
		}
		int val = rec[nums[i]-1];
		lcs[i] = lcs[val]+1;
		pr[i] = val;
		if (lcs[i] > ans) {
			ans = lcs[i];
			spot = i;
		}
	}
	vector<int> pans;
	while (spot != -1) {
		pans.push_back(spot);
		spot = pr[spot];
	}
	reverse(pans.begin(), pans.end());
	cout << ans << endl;
	for (auto v : pans) cout << v << " ";
	cout << endl;
	cin >> n;

}