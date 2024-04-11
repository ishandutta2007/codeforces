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

ll n, A[MAXN];

inline bool check(int k) {
	multiset<int> st;
	for (int i = 1; i <= n; i++) st.insert(A[i]);

	for (int i = 1; i <= k; i++) {
		int x = k - i + 1;
		auto it = st.lower_bound(x + 1);

		if (it == st.begin()) return false;
		st.erase(prev(it));

		if (i < k) {
			int t = *st.begin();
			st.erase(st.begin());
			st.insert(t + x);
		}
	}
	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (check(i))
				ans = i;
		cout << ans << endl;	
	}
	return 0;
}