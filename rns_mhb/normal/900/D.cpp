#include <bits/stdc++.h>
using namespace std;
#define N 35000
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const int p = 1e9 + 7;

ll expmod(ll a, ll b, ll mod) {
	ll rlt = 1;
	for (a %= mod; b; a = a * a % mod, b >>= 1) if (b & 1) rlt = rlt * a % mod;
	return rlt;
}

int x, y;

vector<int>v, w;
vector<pii>u;
void prime() {
	bool vis[N] = {};
	for (int i = 2; i < N; i ++) if (!vis[i]) {
		v.pb(i);
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

int main() {
	prime();
	scanf("%d%d", &x, &y);
	if (y % x) puts("0");
	else {
		y /= x;
		int yy = y;
		for (int i = 0; i < v.size(); i ++) if (y % v[i] == 0) {
			w.pb(v[i]);
			while (y % v[i] == 0) y /= v[i];
		}
		if (y > 1) w.pb(y);
		y = yy;
		u.pb(mp(1, 1));
		int ans = 0;
		for (int i = 0; i < w.size(); i ++) {
			int n = u.size();
			for (int j = 0; j < n; j ++) u.pb(mp(w[i] * u[j].first, -u[j].second));
		}
		for (int i = 0; i < u.size(); i ++) {
			ans += u[i].second * expmod(2, y / u[i].first - 1, p);
			ans = (ans % p + p) % p;
		}
		cout<<ans;
	}
    return 0;
}