#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, k;
	cin >> n >> x >> k;
	int nums[n+1];
	vector<int> nu;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		nu.push_back(nums[i]);
	}	
	map<int, int> vbef;
	sort(nu.begin(), nu.end());
	ll ans = 0LL;
	for (int i = 0; i < n; i++) {
		int cur = nu[i];
		int nbef = cur/x;
		if (cur % x == 0) nbef--;
		if (vbef.count(nbef) > 0) {
			vbef[nbef]++;
		}
		else vbef[nbef] = 1;

		if (i == n-1 || nu[i] != nu[i+1]) {
			for (int j = i; j>= 0; j--) {
				if (nu[j] != nu[i]) break;
				int cur2 = nu[i];
				int val2 = cur2/x;
				int oth2 = val2-k;
				if (vbef.count(oth2) > 0) {
					ans = ans + (vbef[oth2]+0LL);
				}
			}
		}
	}

	
	cout << ans << endl;
	cin >> ans;
	
	
}