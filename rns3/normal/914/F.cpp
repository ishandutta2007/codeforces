#include <bits/stdc++.h>
using namespace std;

const int K = 26;

#define N 101010

bitset<N> vis[K], all, tmp;

char s[N], t[N];

void print(bitset<N> &g) {
	for (int i = 0; i < 15; i ++) printf("%d ", (int)g[i]);puts("");
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%s", s + 1);
	for (int i = 0; i < N; i ++) all[i] = 1;
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) vis[s[i]-'a'][i] = 1;
	int q;
	scanf("%d", &q);
	while (q --) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int id;
			scanf("%d %s", &id, t);
			vis[s[id]-'a'][id] = 0;
			s[id] = t[0];
			vis[s[id]-'a'][id] = 1;
		}
		else {
			int le, ri;
			scanf("%d %d %s", &le, &ri, t);
			int m = strlen(t);
			if (ri < le + m - 1) {
				puts("0");
				continue;
			}
			ri -= (m - 1);
			tmp = all;
			//tmp >>= (ri + 1);
			tmp <<= (ri + 1);
			tmp ^= all;
			tmp >>= le;
			tmp <<= le;
			for (int i = 0; i < m; i ++) {
				tmp &= (vis[t[i]-'a'] >> i);
			}
			printf("%d\n", (int)tmp.count());
		}
	}

	return 0;
}