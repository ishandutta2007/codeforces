// Sohsoh84 :)))
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

const ll MAXN = 1e3 + 10;

int n;
string s, t;

inline int solve() {
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		string p;
		for (int j = i; j < s.size(); j++) {	
			p.push_back(s[j]);
			string p2 = p;
			int ind = j;
			while (p2.size() < t.size() && ind) {
				ind--;
				p2.push_back(s[ind]);
			}

			if (p2 == t) return cout << "YES" << endl, 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}