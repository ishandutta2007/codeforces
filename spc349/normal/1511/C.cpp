#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[300010];
int vis[60];
vector <pii> all;

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!vis[a[i]]) vis[a[i]] = 1, all.push_back(mp(a[i], i));
	}
	while (q--) {
		int x; scanf("%d", &x);
		for (int i = 0; i < all.size(); i++) {
			if (all[i].fi == x) {
				printf("%d ", all[i].se);
				all.erase(all.begin() + i);
				all.insert(all.begin(), mp(x, 1));
				break;
			}
			all[i].se++;
		}
	}
	printf("\n");
	return 0;
}