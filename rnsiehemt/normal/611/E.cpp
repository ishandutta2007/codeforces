#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, a, b, c, t[200005], ans;
std::multiset<int> s, q;

void f(std::multiset<int> &p) {
	auto it = p.end();
	if (it != p.begin()) {
		it--;
		p.erase(it);
	}
}

int main()
{
	scanf("%d%d%d%d", &N, &a, &b, &c);
	if (a > b) std::swap(a, b);
	if (b > c) std::swap(b, c);
	if (a > b) std::swap(a, b);
	for (int i = 0; i < N; i++) scanf("%d", &t[i]);
	std::sort(t, t+N);
	if (t[N-1] > a+b+c) { printf("-1\n"); return 0; }
	while (N && t[N-1] > b+c) { N--; ans++; }
	for (int i = 0; i < N; i++) s.insert(t[i]);
	while (!s.empty() && *s.rbegin() > a+c) {
		ans++;
		f(s);
		auto it = s.upper_bound(a);
		if (it != s.begin()) { it--; s.erase(it); }
	}
	while (!s.empty() && *s.rbegin() > std::max(c, a+b)) {
		ans++;
		f(s);
		auto it = s.upper_bound(b);
		if (it != s.begin()) { it--; s.erase(it); }
	}
	if (a+b > c) {
		while (!s.empty() && *s.rbegin() > c) {
			ans++;
			f(s);
			auto it = s.upper_bound(c);
			if (it != s.begin()) { it--; s.erase(it); }
		}
		while (!s.empty()) {
			ans++;
			auto it = s.upper_bound(c);
			if (it != s.begin()) { it--; s.erase(it); }
			if (!s.empty() && *s.begin() <= b) {
				it = s.upper_bound(b);
				if (it != s.begin()) { it--; s.erase(it); }
				it = s.upper_bound(a);
				if (it != s.begin()) { it--; s.erase(it); }
			} else {
				it = s.upper_bound(a+b);
				if (it != s.begin()) { it--; s.erase(it); }
			}
		}
	} else {
		int lo = 0, hi = 200005;
		while (lo < hi) {
			int mid = (lo+hi)/2;
			q = s;
			for (int i = 0; i < mid; i++) if (!q.empty()) f(q);
			if (!q.empty() && *q.rbegin() <= a+b) {
				int rem = mid;
				while (rem && !q.empty() && *q.rbegin() > b) {
					rem--;
					f(q);
				}
				while (rem) {
					auto it = q.upper_bound(b);
					if (it != q.begin()) { it--; q.erase(it); }
					it = q.upper_bound(a);
					if (it != q.begin()) { it--; q.erase(it); }
					rem--;
				}
			}
			if (q.empty()) hi = mid;
			else lo = mid+1;
		}
		ans += lo;
	}
	printf("%d\n", ans);
}