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

const ll MAXN = 12;
const ll MAXM = 1e4 + 5;

int n, m, f[MAXM];
bool B[MAXM][MAXN], T[MAXN];
ll ans = 0, ans_mask = 0, P[MAXM], X[MAXN];
vector<int> vec;

inline ll calc() {
	ll tans = 0;

	for (int i = 1; i <= n; i++) {
		if (T[i]) tans -= X[i];
		else tans += X[i];
	}

	for (int i = 1; i <= m; i++) {
		P[i] = 0;
		for (int j = 1; j <= n; j++) {
			if (B[i][j]) {
				if (T[j]) P[i]++;
				else P[i]--;
			}
		}
	}

	sort(all(vec), [] (int i, int j) {
		return P[i] < P[j];
	});


	for (int i = 0; i < m; i++)
		tans += (i + 1) * P[vec[i]];
	
	return tans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {	
		cin >> n >> m;
		ans = ans_mask = 0;
		vec.clear();
		for (int i = 1; i <= m; i++) vec.push_back(i);
	
		for (int i = 1; i <= n; i++) cin >> X[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				B[j][i] = (c == '1');
			}
		}

		for (int mask = 0; mask < (1 << n); mask++) {
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) T[i + 1] = true;
				else T[i + 1] = false;
			}

			ll c = calc();
			if (c > ans) {
				ans = c;
				ans_mask = mask;
			}
		}

		for (int i = 0; i < n; i++) {
			if (ans_mask & (1 << i)) T[i + 1] = true;
			else T[i + 1] = false;
		}

		calc();
		for (int i = 0; i < m; i++)
			f[vec[i]] = i + 1;
		for (int i = 1; i <= m; i++)
			cout << f[i] << sep;
		cout << endl;
	}
	return 0;
}