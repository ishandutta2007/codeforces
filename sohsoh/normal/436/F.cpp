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

const ll MAXN = 1e5 + 10;
const ll SQ = 380;

ll n, w, C[2 * MAXN], lz[SQ];
vector<int> P_vec[2 * MAXN];
vector<pair<int, ll>> ch[SQ];
int F[SQ];

//wtf

inline ll wtf(int i, int j) {
	return (C[i] * i - C[j] * j + (j - i - 1)) / (j - i);
}

inline void t_add(int l, int r) {
	int ind = l / SQ;
	for (int i = l; i <= r; i++) C[i]++;
	for (int i = ind * SQ; i < (ind + 1) * SQ; i++) C[i] += lz[ind];
	lz[ind] = 0;

	ch[ind].clear();
	ch[ind].push_back({ind * SQ, 0});
	
	for (int i = ind * SQ + 1; i < (ind + 1) * SQ; i++) {
		while (!ch[ind].empty()) {
			ll x = wtf(ch[ind].back().X, i);	
			if (x <= ch[ind].back().Y) ch[ind].pop_back();
			else {
				ch[ind].push_back({i, x});
				break;
			}
		}
	
		if (ch[ind].empty()) ch[ind].push_back({i, 0});
	}


	F[ind] = 0;
}

inline void add(int p) {
	int l = 0, r = p;
	if (r / SQ == l / SQ) {
		t_add(l, r);
		return;
	}

	t_add(r - r % SQ, r);
	t_add(l, (l / SQ + 1) * SQ - 1);
	for (int i = l / SQ + 1; i < r / SQ; i++) {
		lz[i]++;
		while (F[i] < int(ch[i].size()) - 1 && ch[i][F[i] + 1].Y <= lz[i])
			F[i]++;
	}
}

inline pll query() {
	pll ans = {0, 0};
	for (int i = 0; i <= (MAXN - 1) / SQ; i++) {
		ans = max(ans, make_pair((C[ch[i][F[i]].X] + lz[i]) * ch[i][F[i]].X, 1ll * ch[i][F[i]].X));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> w;
	int mx = 0;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		P_vec[b].push_back(a);
		mx = max(mx, b);
	}

	for (int l = 0; l < MAXN; l += SQ)
		ch[l / SQ].push_back({l, 0});

	for (int i = 0; i <= mx + 1; i++) {
		pll e = query();
		cout  << 1ll * w * i * n + e.X << sep << e.Y << endl;
		for (int p : P_vec[i])
			add(p), n--;
	}
	return 0;
}