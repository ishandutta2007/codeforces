#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 23;
int comp[MAX], in[MAX], cc, n, m;

void dfs(int s, int x) {
	comp[s] = x;
	if(s < (1 << n)) {
		if(in[s] && !comp[(1 << n) + s])
			dfs((1 << n) + s, x);
		for(int b = 0; b < n; b++)
			if(s & (1 << b))
				if(!comp[s ^ (1 << b)])
					dfs(s ^ (1 << b), x);
		return;
	}
	int to = ((1 << n) - 1)^(s - (1 << n));
	if(!comp[to])
		dfs(to, x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		in[x] = 1;
	}
	for(int i = 0; i < (1 << n); i++) {
		if(in[i] & !comp[(1 << n) + i]) {
			cc++;
			dfs((1 << n) + i, cc);
		}
	}
	cout << cc << '\n';
}