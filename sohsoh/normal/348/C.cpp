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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQ = 316;

int n, m, q, ind[MAXN], U[MAXN][MAXN / SQ + 10];
vector<vector<int>> S1, S2;
ll A[MAXN], R[MAXN], V[MAXN];
bool B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		if (k > SQ) {
			B[i] = true;
			ind[i] = S2.size();
			S2.push_back({});
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				S2.back().push_back(x);
				V[ind[i]] += A[x];
			}
		} else {
			ind[i] = S1.size();
			S1.push_back({});
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				S1.back().push_back(x);
			}
		}
	}

	for (int i = 0; i < S2.size(); i++) {
		bitset<MAXN> t;
		for (int e : S2[i]) t[e] = true;
		for (int j = 1; j <= m; j++) {
			vector<int> v;
			if (B[j]) v = S2[ind[j]];
			else v = S1[ind[j]];
			for (int e : v)
				if (t[e]) U[j][i]++;
		}
	}

	while (q--) {
		char c;
		cin >> c;
		if (c == '+') {
			ll i, x;
			cin >> i >> x;
			for (int j = 0; j < S2.size(); j++) V[j] += x * U[i][j];
			if (!B[i]) {
				for (int e : S1[ind[i]]) 
					A[e] += x;	
			} else R[ind[i]] += x;
		} else {
			int i;
			cin >> i;
			if (B[i]) cout << V[ind[i]] << endl;	
			else {
				ll ans = 0;
				for (int e : S1[ind[i]]) ans += A[e];
				for (int j = 0; j < S2.size(); j++)
					ans += R[j] * U[i][j];
				cout << ans << endl;
			}
		}
	}
	return 0;
}