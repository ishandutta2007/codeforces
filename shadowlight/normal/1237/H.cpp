#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string s, t;

void reverse_prefix(int len) {
	for (int i = 0; i < len; i++) {
		if (i >= len - 1 - i) break;
		swap(s[i], s[len - 1 - i]);
	}
}

void solve() {
	cin >> s >> t;
	int n = s.size();
	int zs = 0, os = 0, zt = 0, ot = 0;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			if (s[i] == '1') {
				os++;
			} else {
				zs++;
			}
		} 
		if (t[i] == t[i + 1]) {
			if (t[i] == '1') {
				ot++;
			} else {
				zt++;
			}
		}
	}
	if (zs != zt || os != ot) {
		cout << "-1\n";
		return;
	}

	vector <int> ops;

	string ss = s;

	int iter = 0;

	do {
		ops.clear();
		s = ss;

		for (int i = n - 2; i >= 0; i -= 2) {
			if (s[i] == t[i] && s[i + 1] == t[i + 1]) continue;
			
			vector <int> mas;

			for (int j = 0; j <= i; j += 2) {
				if (s[j] == t[i] && s[j + 1] == t[i + 1]) {
					mas.push_back(j);
				}
			}

			bool fl = false;

			if (!mas.size()) {
				fl = true;
				for (int j = 0; j <= i; j += 2) {
					if (s[j] != t[i] && s[j + 1] != t[i + 1]) {
						mas.push_back(j);
					}
				}
			}

			assert(mas.size());
			int pos = mas[rand() % mas.size()];

			ops.push_back(pos + 2);
			reverse_prefix(pos + 2);
			if (fl) {
				ops.push_back(2);
				reverse_prefix(2);
			}
			ops.push_back(i + 2);
			reverse_prefix(i + 2);

			assert(s[i] == t[i] && s[i + 1] == t[i + 1]);
		}
	} while (ops.size() > n + 1);
	cout << ops.size() << "\n";
	for (int x : ops) {
		cout << x << " ";
	}
	cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}