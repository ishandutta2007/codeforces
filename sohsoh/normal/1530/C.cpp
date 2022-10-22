// Um_nlk :)))))
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

int n;
multiset<int> st1, st2, rm1, rm2;

inline void solve() {
	cin >> n;
	
	ll s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st1.insert(x);
		s1 += x;
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st2.insert(x);
		s2 += x;
	}

	for (int i = 0; i < n / 4; i++) {
		s1 -= *st1.begin();
		s2 -= *st2.begin();
		rm1.insert(*st1.begin());
		rm2.insert(*st2.begin());
		st1.erase(st1.begin());
		st2.erase(st2.begin());
	}

	int ans = 0;
	while (s1 < s2) {
		ans++;
		n++;
		st1.insert(100);
		st2.insert(0);

		while (rm2.size() && *rm2.rbegin() > *st2.begin()) {
			s2 += (*rm2.rbegin() - *st2.begin());
			rm2.insert(*st2.begin());
			st2.erase(st2.begin());

			st2.insert(*rm2.rbegin());
			rm2.erase(rm2.find(*rm2.rbegin()));
		}

		s1 += 100;
		if (n % 4 == 0) {	
			s1 -= *st1.begin();
			s2 -= *st2.begin();
			
			rm1.insert(*st1.begin());
			rm2.insert(*st2.begin());
			
			st1.erase(st1.begin());
			st2.erase(st2.begin());	
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		st1.clear();
		st2.clear();
		rm1.clear();
		rm2.clear();
		solve();
	}
	return 0;
}