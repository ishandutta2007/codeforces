#include <bits/stdc++.h>

using namespace std;

long long a[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int m;
	scanf("%d", &m);
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%lld", &a[i]);
	}
	multiset<long long> s;
	long long sum = 0;
	for (int i = 0; i < m; ++i) {
		if (sum + a[i] >= 0) {
			sum += a[i];
			s.insert(a[i]);
			++cnt;
		} else if (!s.empty() && a[i] > *s.begin()) {
			sum -= *s.begin();
			s.erase(s.begin());
			sum += a[i];
			s.insert(a[i]);
		}
	}
	printf("%d\n", cnt);
	return 0;
}