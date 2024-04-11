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
const ll INF = 4e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 64;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll poww(ll a, ll b, ll md) {
	a %= md;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % md;
		b >>= 1;
		a = a * a % md;
	}

	return ans;
}

inline ll poww2(ll a, ll b) {
	if (a == 1) return 1;
	ll ans = 1;
	while (b--) {
		if (INF / a < ans) return INF;
		ans *= a;
	}

	return ans;
}

inline bool Prime(ll n) {
	if (n < 4) return n == 2 || n == 3;
	
	int T = 50;
	while (T--) {
		ll a = 2 + rng() % (n - 3);
		if (poww(a, n - 1, n) != 1) return false;
	}

	return true;
}

inline ll PrimeBase(ll n) {
	for (int i = 1; i < LOG; i++) {
		ll L = 2, R = INF;
		while (L < R) {
			ll mid = (L + R) >> 1;
			if (poww2(mid, i) >= n) R = mid;
			else L = mid + 1;
		}
		
		if (poww2(L, i) == n && Prime(L)) return L;
	}

	return 1;
}

int n, k;
ll A[MAXN], P[MAXN], B[MAXN];
map<ll, vector<ll>> mp;
vector<ll> PrimeReq[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (k == 1) return cout << 0 << endl, 0;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		P[i] = PrimeBase(A[i]);
		B[i] = A[i];
		if (P[i] > 1) mp[P[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (P[i] > 1 && mp[P[i]].size() == 1) mp.erase(P[i]);
	for (int i = 1; i <= n; i++) {
		if (P[i] > 1) continue;
		for (int j = 1; j <= n; j++) {
			if (P[j] > 1 && A[i] % P[j] == 0 && mp.find(P[j]) != mp.end()) {
				while (A[i] % P[j] == 0) A[i] /= P[j];
			       	PrimeReq[i].push_back(P[j]);
			}
		}
	}

	int s = 0;
	for (auto e : mp) s += e.Y.size();

	if (s <= k) {
		vector<int> ans;
		for (auto e : mp)
			for (int i : e.Y)
				ans.push_back(i);

		for (int i = 1; i <= n; i++)
			if (P[i] == 1 && A[i] == 1 && ans.size() < k) 
				ans.push_back(i);

		if (ans.size() < k) cout << 0 << endl;
		else {
			for (int e : ans) cout << B[e] << sep;
			cout << endl;
		}

		return 0;
	}

	vector<pair<ll, pair<ll, vector<ll>>>> V;
	for (auto e : mp) V.push_back({e.Y.size(), e});
	sort(all(V));
	reverse(all(V));

	vector<int> ans;
	if (V.front().X > 2 || k % 2 == 0) {
		for (auto e : V) {
			for (int t : e.Y.Y) ans.push_back(t), k--;
			if (k < 0) {
				if (-k == int(e.Y.Y.size()) - 1) {
					k++;
					ans.erase(ans.begin());
				}

				while (k < 0) ans.pop_back(), k++;
			}

			if (k == 0) {
				for (int e : ans) cout << B[e] << sep;
				cout << endl;
				return 0;
			}				
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (P[i] > 1 || A[i] > 1 || PrimeReq[i].size() * 2 >= k) continue;
		ans.push_back(i);
		k--;
		for (ll e : PrimeReq[i])
			for (int j : mp[e]) ans.push_back(j), k--;
		for (auto e : V) {
			if (k == 0) break;
			for (int ind : e.Y.Y)
				if (find(all(ans), ind) == ans.end())
					ans.push_back(ind), k--;
		}

		for (int e : ans) cout << B[e] << sep;
		cout << endl;
		return 0;
	}

	cout << 0 << endl;
	return 0;
}