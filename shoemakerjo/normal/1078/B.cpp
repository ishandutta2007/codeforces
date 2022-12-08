#include <bits/stdc++.h>

using namespace std;
#define maxn 101
#define ll long long
int n;
int a[maxn];
bool reach[maxn*maxn][maxn];
bool rd[maxn*maxn][maxn]; //reach from some nonzero spot

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	map<int, int> ct;
	set<int> nums;
	for (int i = 1; i <= n; i++) {
		nums.insert(a[i]);
		ct[a[i]]++;
	}
	reach[0][0] = true;
	for (int val : nums) {
		int curct = ct[val];
// 		cout << "on val: " << val << endl;
		for (int i = n*100; i >= 0; i--) {
			for (int j = n; j >= 0; j--) {
				for (int k = 1; k <= curct; k++) {
					if (i-k*val >= 0 && j-k >= 0 && reach[i-k*val][j-k]) {
						reach[i][j] = true;
						if (i-k*val != 0) rd[i][j] = true;
					}
				}
			}
		}

	}
	
	if (nums.size() == 1) {
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for (int val : nums) {
		int curct = ct[val];
		for (int i = 1; i <= curct; i++) {
			if (!rd[i*val][i]) {
				ans = max(ans, i);
			}
		}
	}
	if (nums.size() == 2) {
		int val = *(nums.begin());
		int fct = ct[val];

		if (!rd[fct*val][fct]) {
			ans = n;
		}
	}


	cout << ans << endl;
}