#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n >> q;
		int h, w;
		int lim = 1000;
		vector<vector<long long>> a(lim, vector<long long>(lim, 0));
		for(i=0; i<n; i++) {
			cin >> h >> w;
			a[h-1][w-1] += h*w;
		}
		vector<vector<long long>> sum(lim+1, vector<long long>(lim+1, 0));
		for(i=1; i<=lim; i++) {
			for(j=1; j<=lim; j++) {
				sum[i][j] = a[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
		int h1, h2, w1, w2;
		for(int ql=0; ql<q; ql++) {
			cin >> h1 >> w1 >> h2 >> w2;
			h2--, w2--;
			cout << sum[h2][w2]-sum[h1][w2]-sum[h2][w1]+sum[h1][w1] << endl;
		}
	}
}