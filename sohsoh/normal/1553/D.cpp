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

string s, t;

inline int solve() {
	cin >> s >> t;
	reverse(all(s));
	reverse(all(t));
	
	string ans;
	for (int i = 0; i < s.size(); i++) {
		if (ans.size() < t.size() && i % 2 == ans.size() % 2 && t[ans.size()] == s[i]) 
			ans.push_back(s[i]);
	}	

	cout << (ans == t ? "YES" : "NO") << endl;
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