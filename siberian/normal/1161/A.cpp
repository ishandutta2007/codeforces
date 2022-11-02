#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, k;
vector <int> a;
void read() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
}

int ans;

void run() {
	ans = 0;
	vector <int> first_pos(n + 10, -1);
	for (int i = 0; i < k; i++) {
		if (first_pos[a[i]] == -1) {
			first_pos[a[i]] = i;
		}
	}

	vector <vector <int> > check(n + 1, vector <int> (3, 1));
	check[1][0] = 0;
	check[n][2] = 0;

	vector <int> used(n + 1, 0);
	for (int i = k - 1; i >= 0; i--) {
		if (a[i] > 1) {
			if (used[a[i] - 1])
				check[a[i]][0] = 0;
		}
		if (a[i] < n) {
			if (used[a[i] + 1])
				check[a[i]][2] = 0;
		}
		check[a[i]][1] = 0;
		used[a[i]] = 1;
	}

	/*cout << "check = " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cout << check[j][i] << " ";
		}
		cout << endl;
	}*/

	for (int i = 1; i <= n; i++) {
		ans += check[i][0] + check[i][1] + check[i][2];
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}