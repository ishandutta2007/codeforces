#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string st = "";

char a[107][107];
char res[107][107];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'R') {
				cnt++;
			}
		}
	}
	int d = cnt / k;
	int ost = cnt % k;
	int now = 0, r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int jj = (i % 2 ? m - j - 1 : j);
			if (a[i][jj] == 'R') {
				r++;
			}
			res[i][jj] = st[now];
			if (r == d + (ost > 0)) {
				now++;
				if (now == k) now--;
				r = 0;
				if (ost) ost--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j];
		}
		cout << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < 10; i++) {
		st += (char) (i + '0');
	}
	for (int i = 0; i < 26; i++) {
		st += (char) (i + 'a');
		st += (char) (i + 'A');
	}
	for (int i = 0; i < t; i++) {
		solve();
	}

}