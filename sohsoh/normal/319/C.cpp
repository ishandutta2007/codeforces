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
const ll INF = 8e18;

ll n, A[MAXN], B[MAXN], dp[MAXN], sz;
pair<ll, pll> ch[MAXN];

inline ll f(pll a, pll b) {
	if (a.X == b.X)
		return (a.Y > b.Y ? 1 : -1) * INF;
	
	if (b.X < a.X) swap(a, b);
	return (a.Y - b.Y + (a.Y - b.Y >= 0) * (b.X - a.X - 1)) / (b.X - a.X);
}

inline void addLine(ll lm, ll lx) {
	pll line = {lm, lx};
	while (sz) {
		ll x = f(line, ch[sz - 1].Y);
		if (x > ch[sz - 1].X) {
			ch[sz++] = {x, line};
			return;
		}
		
		sz--;
	}	

	ch[sz++] = {-INF, line};
}

inline ll query(ll x) {
	pll line = prev(lower_bound(ch, ch + sz, make_pair(x, pll(INF, INF)))) -> Y;
	return x * line.X + line.Y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];

	dp[1] = 0;
	addLine(B[1], 0);

	for (int i = 2; i <= n; i++) {
		dp[i] = query(A[i]);
		addLine(B[i], dp[i]);
	}

	cout << dp[n] << endl;
	return 0;
}