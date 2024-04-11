#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		vector<vector<int>> a(2);
		vector<int> sum(2, 0);
		for(i=0; i<n-2; i++) {
			a[i%2].push_back(i);
			sum[i%2] ^= i;
		}
		if(sum[0] == sum[1]) {
			int idx = (n+1)%2;
			sum[idx] ^= a[idx].back();
			a[idx].back()++;
			sum[idx] ^= a[idx].back();
		}
		a[0].push_back(sum[0]^(1<<30));
		a[1].push_back(sum[1]^(1<<30));
		for(i=0; i<n; i++) {
			cout << a[i%2][i/2] << " ";
		}
		cout << endl;
	}
}