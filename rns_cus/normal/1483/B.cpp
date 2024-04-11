#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define N 100100

int n, a[N], nxt[N];
set <int> S;

int find_nxt(int x) {
	if (S.empty()) return 0;
	auto it = S.lower_bound(x);
	if (it != S.end()) return *it;
	else return *S.begin();
}

int find_prv(int x) {
	if (S.empty()) return 0;
	auto it = S.lower_bound(x);
	if (it != S.begin()) return *--it;
	else return *S.rbegin();
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		S.clear();
		for (int i = 1; i <= n; i ++) S.insert(i), scanf("%d", &a[i]), nxt[i] = i + 1; nxt[n] = 1;
		int cur = 1;
		vector <int> ans;
		while (!S.empty()) {
			int p = find_nxt(nxt[cur]);
			if (__gcd(a[find_prv(p)], a[p]) > 1) {
				if (cur == p) break;
				nxt[cur] = nxt[p], cur = p;
			}
			else {
				ans.push_back(p), S.erase(p), nxt[cur] = find_nxt(p);
				cur = nxt[cur];
			}
		}
		printf("%d", ans.size());
		for (auto x : ans) printf(" %d", x); puts("");
    }

    return 0;
}