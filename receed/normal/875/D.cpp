#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<int> a(n), lm(n), rm(n), lo(n, -1), ro(n, n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.back()] < a[i])
			s.pop_back();
		lm[i] = s.empty() ? -1 : s.back();
		s.push_back(i);
	}
	s.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && a[s.back()] <= a[i])
			s.pop_back();
		rm[i] = s.empty() ? n : s.back();
		s.push_back(i);
	}
	for (int i = 0; i < 31; i++) {
		int li = -1;
		for (int j = 0; j < n; j++) {
			if (a[j] & (1 << i))
				li = j;
			else
				lo[j] = max(lo[j], li);
		}
		li = n;
		for (int j = n - 1; j >= 0; j--) {
			if (a[j] & (1 << i))
				li = j;
			else
				ro[j] = min(ro[j], li);
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (long long) (i - lm[i]) * (rm[i] - i);
		ans -= (long long) (i - max(lo[i], lm[i])) * (min(ro[i], rm[i]) - i);
	}
	printf("%lld\n", ans);
}