#include <bits/stdc++.h>

using namespace std;



#define N 101010



vector <int> v[N<<1];

int x[N], y[N];

bool vis[N<<1];

const int mod = 1e9 + 7;

int q[N<<1];



int go[N<<1];

bool hel[N<<1];

bool kick[N<<1];



map <int, bool> mp;

map <int, bool> :: iterator it;



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) {

		scanf("%d %d", &x[i], &y[i]);

		v[y[i]].push_back(x[i]);

		vis[x[i]] = 1;

		go[x[i]] = y[i];

	}

	int ans = 1;

	for (int i = 1; i <= n * 2; i ++) if (!vis[i]) {

		int e = 0;

		q[++e] = i;

		for (int f = 1; f <= e; f ++) {

			int x = q[f];

			for (int j = 0; j < v[x].size(); j ++) {

				int y = v[x][j];

				q[++e] = y;

			}

		}

		for (int f = 1; f <= e; f ++) hel[q[f]] = 1;

		ans = 1ll * ans * e % mod;

	}

	for (int i = 1; i <= n * 2; i ++) if (!hel[i] && go[i] != i) {

		mp.clear();

		mp[i] = 1;

		int j = go[i];

		bool bad = 0;

		while (!mp[j]) {

			if (hel[j] || go[j] == j) {

				bad = 1;

				break;

			}

			mp[j] = 1;

			j = go[j];

		}

		for (it = mp.begin(); it != mp.end(); it ++) {

			hel[it->first] = 1;

		}

		if (!bad) ans = (ans << 1) % mod;

	}

	printf("%d\n", ans);



	return 0;

}