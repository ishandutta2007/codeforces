#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int a = i, b = (i + n - 1) % n;
			if (s[a] == '-' || s[b] == '-') {
				++cnt;
			}
		}
		bool good = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '<') {
				good = false;
			}
		}
		if (good) {
			cnt = n;
		}
		good = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '>') {
				good = false;
			}
		}
		if (good) {
			cnt = n;
		}
		cout << cnt << "\n";
	}
}