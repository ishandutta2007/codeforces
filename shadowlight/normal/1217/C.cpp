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
	string s;
	cin >> s;
	int n = s.size();
	int pr = -1;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			int now = 0; 
			for (int j = 0; j < 20; j++) {
				if (i + j >= n) break;
				now = now * 2 + (s[i + j] - '0');
				if (now < j + 1) continue;
				int len = now - j - 1;
				if (i - len <= pr) continue;
				res++;
			}
			pr = i;
		}
	}	
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}