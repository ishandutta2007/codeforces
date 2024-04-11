#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using LL = long long;
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		multiset<int> S;
		LL sum = 0;
		rep(i, 0, n - 1) {
			int x;
			scanf("%d", &x);
			sum += x;
			S.insert(x);
		}
		priority_queue<LL> pq;
		auto ps = [&](LL x) {
			auto it = S.lower_bound(x);
			if (it != S.end() && *it == x) {
				S.erase(it);
				return;
			}
			pq.push(x);
		};
		ps(sum);
		rep(i, 1, n - 1) {
			LL x = pq.top();
			pq.pop();
			ps(x / 2);
			ps((x + 1) / 2);
		}
		if (pq.empty())
			puts("YES");
		else
			puts("NO");
	}
}