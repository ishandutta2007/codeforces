#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

string sum(char a, char b) {
	int x = (a - '0'), y = (b - '0');
	int c = x + y;
	return to_string(c);
}

inline void print(string s, int i) {
	for (int j = 0; j < i; j++) cout << s[j];
	cout << sum(s[i], s[i + 1]);
	for (int j = i + 2; j < int(s.size()); j++)
		cout << s[j];
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		int ans = -1;
		for (int i = 0; i < n - 1; i++) {
			if (sum(s[i], s[i + 1]).size() > 1) ans = i;
		}

		if (ans >= 0) {
			print(s, ans);
			continue;
		}

		for (int i = 0; i < n - 1; i++) {
			if (s[i + 1] != '0' || i + 1 == n - 1) {
				print(s, i);
				break;
			}
		}
	}
	return 0;
}