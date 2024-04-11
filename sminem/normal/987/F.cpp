#include <bits/stdc++.h>
using namespace std;

bool a[1 << 22];

int n, m;
bool instack[1 << 22];
vector<int> sccstack;
int idx[1 << 22], low[1 << 22];
int sol[1 << 22], t;

void scc(int x) {
	instack[x] = true;
	sccstack.push_back(x);
	low[x] = idx[x] = t++;

	for (int i=0; i<n; i++) {
		if (!(x & (1 << i)))
			continue;

		int y = x - (1 << i);

		if (instack[y]) {
			low[x] = min(low[x], idx[y]);
		} else if (idx[y] == -1) {
			scc(y);
			low[x] = min(low[x], low[y]);
		}
	}

	if (a[x]) {
		int y = (1 << n) - 1 - x;

		if (instack[y]) {
			low[x] = min(low[x], idx[y]);
		} else if (idx[y] == -1) {
			scc(y);
			low[x] = min(low[x], low[y]);
		}
	}

	if (low[x] == idx[x]) {
		vector<int> komp;
		while (1) {
			int z = sccstack.back();
			komp.push_back(z);
			sccstack.pop_back();
			instack[z] = false;
			if (z == x)
				break;
		}
		int mn = *min_element(komp.begin(), komp.end());
		for (int x : komp)
			sol[x] = mn;
	}
}

bool ima[1 << 22];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// igrajse(3);
	
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		a[x] = 1;
	}

	fill(idx, idx+(1<<n), -1);

	for (int i=0; i<(1<<n); i++)
		if (idx[i] == -1)
			scc(i);

	for (int i=0; i<(1<<n); i++)
		if (a[i])
			ima[sol[i]] = true;

	cout << count(ima, ima+(1<<n), true);
	
}