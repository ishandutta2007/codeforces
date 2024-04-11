#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;
int prime[MAXN];

void sieve() {
	for(int p = 2; p < MAXN; p++) {
		if(prime[p])
			continue;
		for(int q = p; q < MAXN; q += p)
			prime[q] = p;
	}
}

ll pow(ll b, ll e) {
	ll res = 1;
	for(ll k = 1; k <= e; k *= 2) {
		if(k & e) {
			if(res < INF/b)
				res = res * b;
			else
				return INF;
		}
		if(b < INF/b)
			b = b * b;
		else
			b = INF;

	}
	return res;
}

int cnt[MAXN], a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sieve();

	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	ll ans = 0;
	map<vector<ii>, int> ocnt;
	for(int i = 0; i < n; i++) {
		int x = a[i];
		vector<ii> v;
		while(x > 1) {
			int p = prime[x], e = 0;
			while(x % p == 0) {
				x /= p;
				e++;
			}
			e %= k;
			if(e)
				v.push_back({p, e});
		}
		vector<ii> vx;
		for(auto p : v)
			vx.push_back({p.first, k - p.second});
		ans += ocnt[vx];
		ocnt[v]++;
	}
	cout << ans << '\n';
}