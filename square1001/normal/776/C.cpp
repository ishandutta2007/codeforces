#include <bits/stdc++.h>
using namespace std;
int n, m; long long a[100009];
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
	long long z = 1, ret = 0;
	set<long long> s;
	for(int i = 0; i < 50 && abs(z) <= 1LL << 50; i++) {
		if(s.count(z)) continue;
		s.insert(z);
		map<long long, int> d;
		for(int j = 0; j <= n; j++) {
			ret += d[a[j] - z];
			d[a[j]]++;
		}
		z *= m;
	}
	printf("%lld\n", ret);
	return 0;
}