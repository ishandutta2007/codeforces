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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
string s;
vector<int> v[4];

inline void solve() {
	cin >> s;
	n = s.size();

	v[0].clear();
	v[1].clear();
	v[2].clear();
	v[3].clear();

	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') v[0].push_back(i);
		if (s[i] == 'N') v[1].push_back(i);
		if (s[i] == 'T') v[2].push_back(i);
		if (s[i] == 'O') v[3].push_back(i);
	}

	ll ans = -1;
	string ans_s;

	vector<int> p = {0, 1, 2, 3};
	do {
		ll tans = 0;
		string s;
		for (int i = 0; i < 4; i++) {
			for (int e : v[p[i]]) {
				for (int j = i + 1; j < 4; j++) 
					tans += lower_bound(all(v[p[j]]), e) - v[p[j]].begin();
				if (p[i] == 0) s += 'A';
				else if (p[i] == 1) s += 'N';
				else if (p[i] == 2) s += 'T';
				else s += 'O';
			}
		}	
		
		if (tans > ans) {
			ans = tans;
			ans_s = s;
		}
	} while (next_permutation(all(p)));

	cout << ans_s << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}