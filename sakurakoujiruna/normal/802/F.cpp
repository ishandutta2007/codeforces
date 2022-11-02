#include <bits/stdc++.h>
using namespace std;

using db = double;
const int N = 250, M = 1e4L + 11;
int a[N];
db lfac[M];

db uniform(int p) {
	db r = 0;
	for(int i = 0; i < N; i ++)
		if(a[i] < 0 || a[i] > 2 * p)
			return -1e300;
		else
			r += -log(2 * p + 1);
	return r;
}
db poisson(int p) {
	db r = 0;
	for(int i = 0; i < N; i ++)
		if(a[i] < 0)
			return -1e300;
		else
			r += a[i] * log(p) - p - lfac[a[i]];
	return r;
}

int main() {
	for(int i = 1; i < M; i ++)
		lfac[i] = lfac[i - 1] + log(i);

	ios :: sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		for(int i = 0; i < N; i ++)
			cin >> a[i];
		bool uni = 0; db k = -1e300;
		for(int i = 1; i <= 1000; i ++) {
			for(int j = 0; j < N; j ++) a[j] ++;
			db u = uniform(i), p = poisson(i);
			if(u > k) {
				uni = 1;
				k = u;
			}
			if(p > k) {
				uni = 0;
				k = p;
			}
		}
		cout << (uni ? "uniform" : "poisson") << '\n';
	}
}