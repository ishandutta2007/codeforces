#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int n, m;

set<int> adj[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	if (n * 1LL * (n-1LL) / 2LL == m) {
		cout << "NO" << endl;
		return 0;
	}

	int a, b;
	while (m--) {
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}


	for (int i = 1; i <= n; i++) {
		int oval = -1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (adj[i].count(j) == 0) {
				oval = j;
				break;
			}
		}

		if(oval == -1) continue;

		int curval = 3;


		cout << "YES" << endl;

		for (int j = 1; j <= n; j++) {
			if (j == i) cout << 1 << " ";
			else if (j == oval) cout << 2 << " ";
			else {
				cout << curval << " ";
				++curval;
			}
		}
		cout << endl;
		curval = 3;
		for (int j = 1; j <= n; j++) {
			if (j == i) cout << 1 << " ";
			else if (j == oval) cout << 1 << " ";
			else {
				cout << curval << " ";
				++curval;
			}
		}
		cout << endl;

		break;
	}





}