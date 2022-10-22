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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll INF = 1e8;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fen[MAXN], n;
vector<int> v;

inline void add(int ind, ll val) {	
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

inline void Update(int L, int R, ll val) {
	add(L, val);
	add(R + 1, -val);
}

inline ll Query(int ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind) ans += fen[ind];
	return ans;
}

inline void Reset(int ind, ll val) {
	ll c = Query(ind);	
	Update(ind, ind, val - c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (v.empty() || v.back() != x) v.push_back(x);
	}

	for (int i = 1; i <= n; i++) Reset(i, 1e9);
	Reset(v.front(), 1);
	
	ll mn = 1;
	for (int i = 1; i < v.size(); i++) {
		int t = v[i], t2 = v[i - 1];		
		mn++;
		ll k = Query(t);
		Update(1, n, 1);
		Reset(t, min(mn, k));
		Reset(t2, min(mn, k));
		mn = min(mn, k);
	}

	cout << mn << endl;
	return 0;
}