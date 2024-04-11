// \_()_/
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
const ll MOD = 1e9 + 7; 
const ll MOD1 = 1e9 + 7; 
const ll MOD2 = 998244353;

int n, k;
string s;
pll hsh[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll p1, p2, T1[MAXN], T2[MAXN];

ll poww(ll a, ll b, ll md) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % md;
		b >>= 1;
		a = a * a % md;
	}	

	return ans;
}

pll Hsh(int L, int R) {
	pll ans = hsh[R];
	if (L) {
		ans.X = (ans.X - hsh[L - 1].X + MOD1) % MOD1;
		ans.Y = (ans.Y - hsh[L - 1].Y + MOD2) % MOD2;
		ans.X = ans.X * T1[L] % MOD1;
		ans.Y = ans.Y * T2[L] % MOD2;
	}

	return ans;
}

bool Ask(int i, int j) {
	if (Hsh(i, i + n - 1) == Hsh(j, j + n - 1)) return true;
	int L = 0, R = n - 1;
	while (L < R) {
		int mid = (L + R) >> 1;
		if (Hsh(i, i + mid) == Hsh(j, j + mid)) L = mid + 1;
		else R = mid;
	}

	return s[i + L] < s[j + L];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	s = s + s;
		
	p1 = rng() % int(8e8) + 1;
	p2 = rng() % int(8e8) + 1;
	
	ll hsh1 = 0, hsh2 = 0, t1 = 1, t2 = 1;
	for (int i = 0; i < 2 * n; i++) {
		hsh1 = (hsh1 + int(s[i] - 'a') * t1) % MOD1;
		hsh2 = (hsh2 + int(s[i] - 'a') * t2) % MOD2;
		t1 = t1 * p1 % MOD1;
		t2 = t2 * p2 % MOD2;
		hsh[i] = {hsh1, hsh2};
		T1[i] = (poww(poww(p1, i, MOD1), MOD1 - 2, MOD1));
		T2[i] = (poww(poww(p2, i, MOD2), MOD2 - 2, MOD2));
	}
	
	int ind = 0;
	for (int i = 0; i < k; i++) {
		if (Ask(ind, 0)) {
			cout << s[ind];
			ind = (ind + 1) % n;
		} else {
			cout << s[0];
			ind = 1 % n;
		}
	}
	return 0;
}