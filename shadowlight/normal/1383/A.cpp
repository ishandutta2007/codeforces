#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; ++i) {
		if (s[i] > t[i]) {
			cout << "-1\n";
			return;
		}
	}
	int res = 0;
	vector <vector <int> > cnt(26, vector <int> (26, 0));
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) continue;
		cnt[s[i] - 'a'][t[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = i + 1; j < 26; ++j) {
			if (cnt[i][j]) {
				++res;
				for (int d = 0; d < 26; ++d) {
					cnt[j][d] += cnt[i][d];
				}
				break;
			}
		}
	}
	cout << res << "\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}