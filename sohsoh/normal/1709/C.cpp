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

inline bool is_rbs(string& s) {
	int bal = 0;
	for (char c : s) {
		bal += (c == '(' ? 1 : -1);
		if (bal < 0) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		
		int c0 = count(all(s), '('), c1 = count(all(s), ')'), c2 = count(all(s), '?');
		int t = (c0 + c1 + c2) / 2;
		int f0 = t - c0, f1 = t - c1;
		
		if (!f0 || !f1) {
			cout << "YES" << endl;
			continue;
		}

		bool flag = false;
		for (char& c : s) {
			if (c == '?') {
				if (f0 > 1 || (f0 > 0 && flag)) {
					f0--;
					c = '(';
				} else {
					c = ')';
					flag = true;
				}	
			}
		}

		cout << (is_rbs(s) ? "NO" : "YES") << endl;
	}
	return 0;
}