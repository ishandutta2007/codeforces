#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

inline bool Check(string s) {
	int bal = 0;
	for (char c : s) {
		if (c == '(') bal++;
		else bal--;
		if (bal < 0) return false;
	}

	return bal == 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool flag = false;

		for (int i = 0; i < 8; i++) {
			string t = s;
			if (i & 1) replace(all(t), 'A', '(');
			else replace(all(t), 'A', ')');
			if (i & 2) replace(all(t), 'B', '(');
			else replace(all(t), 'B', ')');
			if (i & 4) replace(all(t), 'C', '(');
			else replace(all(t), 'C', ')');
		
			if (Check(t)) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}

		if (!flag) cout << "NO" << endl;
	}
	return 0;
}