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
const ll INF = 8e16;
const ll inf2 = 1e12;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, A[MAXN], D[MAXN];
bool B[MAXN];
vector<ll> seq;

ll nor_lis() {
	fill(D, D + seq.size() + 10, INF);
	D[0] = -INF;

	for (int i = 0; i < seq.size(); i++) {
		ll j = upper_bound(D, D + seq.size() + 10, seq[i]) - D;
		if (D[j - 1] <= seq[i] && seq[i] < D[j]) D[j] = seq[i];
	}

	ll ans = 0;
	for (int i = 0; i < seq.size() + 10; i++) if (D[i] < INF) ans = i;
	return ans;
}

ll L_lis() {	
	fill(D, D + seq.size() + 10, INF);
	D[0] = seq.front();

	for (int i = 0; i < seq.size(); i++) {
		ll j = upper_bound(D, D + seq.size() + 10, seq[i]) - D;
		if (j == 0) continue;
		if (D[j - 1] <= seq[i] && seq[i] < D[j]) D[j] = seq[i];
	}

	ll ans = 0;
	for (int i = 0; i < seq.size() + 10; i++) if (D[i] < INF) ans = i;
	return ans;	
}


ll R_lis() {
	fill(D, D + seq.size() + 10, INF);
	D[0] = -INF;

	for (int i = 0; i < seq.size() - 1; i++) {
		ll j = upper_bound(D, D + seq.size() + 10, seq[i]) - D;
		if (D[j - 1] <= seq[i] && seq[i] < D[j]) D[j] = seq[i];
	}

	return upper_bound(D, D + seq.size() + 10, seq.back()) - D;
}

ll LR_lis() {	
	fill(D, D + seq.size() + 10, INF);
	D[0] = seq.front();
	
	for (int i = 0; i < seq.size() - 1; i++) {
		ll j = upper_bound(D, D + seq.size() + 10, seq[i]) - D;
		if (j == 0) continue;
		if (D[j - 1] <= seq[i] && seq[i] < D[j]) D[j] = seq[i];
	}

	return upper_bound(D, D + seq.size() + 10, seq.back()) - D;
}

ll p_b = -1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	while (k--) {
		ll ind;
		cin >> ind;
		B[ind] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (i < n && B[i] && B[i + 1] && A[i] >= A[i + 1]) return cout << -1 << endl, 0;
		if (B[i]) {
			if (p_b >= 0 && A[i] - A[p_b] < i - p_b) return cout << -1 << endl, 0;
			p_b = i;
		}
	}
	ll ans = 0;
	seq.push_back(-inf2);
	for (int i = 1; i <= n; i++) {
		if (!B[i]) seq.push_back(A[i] - i);
		if (i == n && !B[i]) {
			seq.push_back(inf2);
			if (seq.size() > 2) ans += seq.size() - LR_lis();
		} else if (B[i]) {
			seq.push_back(A[i] - i);
			if (seq.size() > 2) ans += seq.size() - LR_lis();
			seq.clear();
			seq.push_back(A[i] - i);
		}

	}

	cout << ans << endl;
	return 0;
}