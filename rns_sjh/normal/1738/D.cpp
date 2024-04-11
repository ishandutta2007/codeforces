#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 100500;

int n, b[N];

vector<int> vec, p[N];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
		scanf("%d", &n);
		int k(0);
		for (int i = 1; i <= n + 10; i++) p[i].clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			p[b[i]].push_back(i);
			k = max(k, min(i, b[i]));
		}
		printf("%d\n", k);
		queue<int> Q;
		for (int i = 1; i <= n; i++) {
			if (b[i] == n + 1 || !b[i]) Q.push(i);
		}
		vec.clear();
		while (!Q.empty()) {
			vector<int> v;
			while (!Q.empty()) {
				int cur = Q.front(); Q.pop();
				v.push_back(cur);
			}
			int id(-1);
			for (int i = 0; i < v.size(); i++) {
				if (!p[v[i]].empty()) {
					id = i; break;
				}
			}
			for (int i = 0; i < v.size(); i++) {
				if (id != i) vec.push_back(v[i]);
			}
			if (id != -1) {
				vec.push_back(v[id]);
				for (auto x : p[v[id]]) Q.push(x);
			}
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", vec[i], " \n"[i == n - 1]);
    }

    return 0;
}