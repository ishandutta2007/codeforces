#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 500

int rlt[N];
multiset <int> S;

main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n * n; i ++) {
		scanf("%d", &x);
		S.insert(x);
	}
	int cnt = 0;
	while (!S.empty()) {
		multiset <int> :: iterator it = S.end(); it --;
		rlt[cnt ++] = *it;
		S.erase(it);
		for (int i = 0; i < cnt - 1; i ++) {
			int g = __gcd(rlt[cnt - 1], rlt[i]);
			multiset <int> :: iterator ps = S.lower_bound(g);
			S.erase(ps);
			ps = S.lower_bound(g);
			S.erase(ps);
		}
		printf("%d ", rlt[cnt - 1]);
	}
}