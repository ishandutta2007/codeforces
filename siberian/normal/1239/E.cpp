#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int MAXN = 25;
const int MAXW = 25 * 50000;
int p[MAXN][MAXW];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);

	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (auto &i : a)
		cin >> i;

	sort(all(a));
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXW; j++)
			p[i][j] = -1;

	p[0][0] = 0;
	int sum = 0;

	for (int i = 2; i < 2 * n; i++) {
		int cur = a[i];
		sum += cur;
		for (int j = n - 1; j > 0; j--) {
			for (int k = cur; k < MAXW; k++) {
				if (p[j - 1][k - cur] != -1 && p[j][k] == -1) {
					p[j][k] = i;
				}
			}
 		}
	}

	int best = 10 * MAXW;
	for (int i = 0; i < MAXW; i++) {
		if (abs(best - (sum - best)) > abs(i - (sum - i)) && p[n - 1][i] != -1) {
			best = i;
		}
	}
	
	vector<int> type(2 * n);
	type[1] = 1;
	for (int i = n - 1; i > 0; i--) {
		type[p[i][best]] = 1;
		best -= a[p[i][best]];
	}
	vector<int> ans1, ans2;
	for (int i = 0; i < 2 * n; i++) {
		if (type[i] == 0)
			ans1.push_back(a[i]);
		else
			ans2.push_back(a[i]);
	}
	sort(all(ans1));
	sort(all(ans2));
	reverse(all(ans2));
	for (auto i : ans1)
		cout << i << " ";
	cout << endl;
	for (auto i : ans2) 
		cout << i << " ";
	cout << endl; 
 	return 0;
}