#include <bits/stdc++.h>

using namespace std;

int delt[10010];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;


	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		delt[i]++;
		delt[cur]--;
	}

	cur = 0;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		cur += delt[i];

		if (cur == 0) res++;
	}
	// res++;
	cout << res << endl;
}