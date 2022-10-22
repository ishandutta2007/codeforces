#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], B[MAXN];
set<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], st.insert(i);
	
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int p, x;
			cin >> p >> x;
			p--;
			while (x > 0 && st.upper_bound(p) != st.end()) {
				p = *st.upper_bound(p);
				int s = min(A[p] - B[p], x);
				x -= s;
				B[p] += s;
				if (A[p] == B[p]) st.erase(p);
			}
		} else {
			int p;
			cin >> p;
			cout << B[p] << endl;
		}
	}
	return 0;
}