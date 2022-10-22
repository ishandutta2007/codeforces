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

const ll MAXN = 4e6 + 10;

int A[MAXN], n;
vector<int> ans;
inline int ind(int x) {
	for (int i = 1; i <= n; i++)
		if (A[i] == x) return i;
	return 0;
}

inline void op(int ind) {
	reverse(A + 1, A + ind + 1);
	ans.push_back(ind);
}

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	for (int i = 1; i <= n; i++) 
		if (i % 2 != ind(i) % 2)
			return cout << -1 << endl, 0;
	
	for (int i = n; i > 1; i -= 2) {
		int x = i, y = i - 1;
		op(ind(x));
		op(ind(y) - 1);
		int z = A[ind(y) + 1];
		op(ind(z));
		op(3);
		op(i);
	}

	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ans.clear();
		solve();
	}
	return 0;
}