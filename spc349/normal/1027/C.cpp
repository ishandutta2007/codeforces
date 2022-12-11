#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[1000010];
vector <int> all;

pii MIN(pii a, pii b) {
	return 1ll * (a.fi + a.se) * (a.fi + a.se) * b.fi * b.se
		 < 1ll * (b.fi + b.se) * (b.fi + b.se) * a.fi * a.se ? a : b;
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		all.clear();
		for (int i = 0; i < n; i++) {
			int j = i;
			while (j < n && a[i] == a[j]) j++;
			if (j - i >= 2) all.push_back(a[i]);
			if (j - i >= 4) all.push_back(a[i]);
			i = j - 1;
		}
		pii ans = mp(all[0], all[1]);
		for (int i = 1; i < all.size(); i++) {
			ans = MIN(ans, mp(all[i - 1], all[i]));
		}
		printf("%d %d %d %d\n", ans.fi, ans.fi, ans.se, ans.se);
	}
	return 0;
}