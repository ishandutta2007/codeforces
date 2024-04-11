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

int n, A[MAXN];
vector<int> vec[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		A[i] = x;
		vec[x].push_back(i);
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (vec[i].size() & 1) {
			if (flag) return cout << 0 << endl, 0;
			else flag = true;
		}
	}

	int ind = 1;
	while (ind <= n / 2) {
		if (A[ind] != A[n - ind + 1]) break;
		ind++;
	}

	if (ind > n / 2) return cout << 1ll * n * (n + 1) / 2 << endl, 0;

	int a = 0, b = n + 1;
	for (int i = 1; i <= n; i++) {
		if (!vec[i].empty()) {
			int L = 0, R = 0;
			if (vec[i].size() & 1) L = R = vec[i].size() / 2;
			else R = vec[i].size() / 2, L = R - 1;

			while (L >= 0 && vec[i][L] == n + 1 - vec[i][R]) L--, R++;
			if (L >= 0) {
				a = max(a, vec[i][L]);
				b = min(b, vec[i][R]);
			}
		}
	}

	cout << 1ll * ind * (n - a + 1) + 1ll * b * ind - 1ll * ind * ind << endl;
	return 0;
}