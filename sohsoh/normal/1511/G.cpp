#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);	
	
	int n, m;
	cin >> n >> m;
	
	vector<int> C(n);
	for (int i = 0; i < n; i++) cin >> C[i];
	sort(C.begin(), C.end());
	
	int q;
	cin >> q;
	while (q--) {
		int L, R;
		cin >> L >> R;
		int tL = lower_bound(C.begin(), C.end(), L) - C.begin();
		int tR = upper_bound(C.begin(), C.end(), R) - C.begin();
	       	int x = 0;
		for (int i = tL; i < tR; i++) x ^= C[i] - L;
		cout << "AB"[x == 0];
	}

	return 0;
}