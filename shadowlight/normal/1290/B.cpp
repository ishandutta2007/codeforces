#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
const int Q = 31;

int cnt[N][Q];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Q; j++) {
			cnt[i + 1][j] += cnt[i][j];
			if (j + 'a' == s[i]) {
				cnt[i + 1][j]++;
			}
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << "Yes\n";
			continue;
		}
		int len = r - l + 1;
		bool can = true;
		int now = 0;
		for (int j = 0; j < Q; j++) {
			if (cnt[r][j] - cnt[l - 1][j] > 0) {
				now++;
			}
		}
		if (now == 1) {
			cout << "No\n";
			continue;
		}
		if (now >= 3 || s[l - 1] != s[r - 1]) {
			cout << "Yes\n";
			continue;
		}
		cout << "No\n";

	}
}