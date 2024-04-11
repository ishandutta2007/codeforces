#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;

int main() {
	int N, K, M;
	cin >> N >> K >> M;
	map<string, int> mp;
	rep(i, N) {
		string s; cin >> s;
		mp[s] = i;
	}
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<int> i_to_k(N);
	vector<int> mi(K, INT_MAX);
	rep(k, K) {
		int n; scanf("%d", &n);
		while (n--) {
			int i; scanf("%d", &i), i--;
			i_to_k[i] = k;
			mi[k] = min(mi[k], a[i]);
		}
	}
	ll ans = 0;
	rep(j, M) {
		string s; cin >> s;
		int i = mp[s], k = i_to_k[i];
		ans += mi[k];
	}
	cout << ans << endl;
}