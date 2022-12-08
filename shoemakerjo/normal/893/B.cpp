#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> bd;
	int powe = 1;
	int rpow = 0;
	int curadd = 0;
	while (curadd <= n) {
		powe = powe*2;
		if (rpow == 0) rpow = 1;
		else rpow = rpow*2;
		curadd = (powe-1)*rpow;
		bd.push_back(curadd);
	}
	int ans = 1;
	for (int i = 0; i < bd.size(); i++) {
		if (n%bd[i] == 0) ans = bd[i];
	}
	cout << ans << endl;
	cin >> ans;
}