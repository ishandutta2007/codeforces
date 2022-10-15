#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int T, n, a[N], b[N], l[N], r[N], anc[N];
std::multiset<int> set;

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int main() {
    for (int T = read(); T; T--) {
		n = read(); set.clear();
		anc[n + 1] = n + 1;
        for (int u = 1; u <= n; u++) { anc[u] = u; }
		for (int i = 1; i <= n; i++) {
			a[i] = read(); b[a[i]] = i;
			l[i] = r[i] = i; set.insert(1);
		}
        bool flag = true;
		for (int i = 1; i <= n; i++) {
			int u = b[i], v;
			if (r[u] - l[u] + 1 != *set.rbegin()) {
				flag = false; break;
			}
			set.erase(set.find(r[u] - l[u] + 1));
			v = find(r[u] + 1);
			anc[find(u)] = v;
			if (v <= n) {
				set.erase(set.find(r[v] - l[v] + 1));
				l[v] = l[u];
				set.insert(r[v] - l[v] + 1);
			}
		}
        printf("%s\n", flag ? "Yes" : "No");
	}
    return 0;
}