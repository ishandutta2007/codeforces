#include <bits/stdc++.h>
using namespace std;
int n, m, x, c[16388], popcount[16388];
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) scanf("%d", &x), c[x]++;
	for(int i = 1; i < 16384; i++) popcount[i] = popcount[i >> 1] + (i & 1);
	long long ret = 0;
	for(int i = 0; i <= 10000; i++) {
		if(m == 0) ret += 1LL * c[i] * (c[i] - 1) / 2;
		for(int j = i + 1; j <= 10000; j++) {
			if(popcount[i ^ j] == m) ret += 1LL * c[i] * c[j];
		}
	}
	cout << ret << endl;
	return 0;
}