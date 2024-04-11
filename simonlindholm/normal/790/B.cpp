#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, K;
int cost(int i, int j) {
	if (i + j == 0) return 0;
	if (i + j > K) return 2;
	return 1;
}

vector<vi> ed;
struct Res {
	array<ll, 5> counts;
	ll sum;
};

ll res = 0;
Res dfs(int at, int par = -1) {
	array<ll, 5> co{};
	co[0]++;
	ll lsum = 0;
	ll totco = 1;
	ll mres = 0;
	trav(x, ed[at]) if (x != par) {
		Res r2 = dfs(x, at);
		ll r0 = r2.counts[K-1];
		for (int i = K-2; i >= 0; --i) r2.counts[i+1] = r2.counts[i];
		r2.counts[0] = r0;
		rep(i,0,K) co[i] += r2.counts[i];
		r2.sum += r2.counts[0];
		ll mco = 0;
		rep(i,0,K) mco += r2.counts[i];
		lsum += r2.sum;
		totco += mco;
		mres -= r2.sum * mco * 2;
// if (r2.sum * mco) cerr << at << " sub " << r2.sum * mco << endl;
		rep(i,0,K) rep(j,0,K)
			mres -= r2.counts[i] * r2.counts[j] * cost(i, j);
	}
	mres += totco * lsum * 2;
// if (lsum * totco) cerr << at << " add " << lsum * totco << endl;
	rep(i,0,K) rep(j,0,K)
		mres += co[i] * co[j] * cost(i, j);
// cerr << at << ' ' << mres << ' ' << co[0] << ' ' << co[1] << ' ' << lsum << endl;
	res += mres;
	return {co, lsum};
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N >> K;
	ed.resize(N);
	rep(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(0);
	cout << res/2 << endl;
	exit(0);
}