#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define plog(x)			    cerr << #x << ": " << x.X << ", " << x.Y << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 100;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll CST = 2000 + 10;


// L: pos starts(with 0 !!), M1: point with maximum score, M2: last point with maximum score R: end(with 0) !!
int n, m, k, L[MAXN], M1[MAXN], M2[MAXN], R[MAXN];
vector<pll> v;

ll I(pll e1, pll e2) {
	return max(0, min(e1.Y, e2.Y) - max(e2.X, e1.X) + 1);
}

ll helper(pll seg) {
	memset(L, 0, sizeof L);
	memset(M1, 0, sizeof M1);
	memset(M2, 0, sizeof M2);
	memset(R, 0, sizeof R);

	for (pll e : v) {
		ll sc = I(e, seg);
		
		//L: 
		ll tr = e.X + sc - 1;
		L[tr - k + 1]++;

		//R:
		R[e.Y - sc + 1]++;

		//M:
		if (k < e.Y - e.X + 1) {
			M1[e.X]++;
			M2[e.Y - k + 1]++;
		} else {
			M1[e.Y - k + 1]++;
			M2[e.X]++;
		}
	}

	ll ans = 0, pos = 0, neg = 0, score = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(score, ans);
		score -= neg;
		score += pos;
		pos -= M1[i];
		neg += M2[i];

		pos += L[i];
		neg -= R[i];
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l += CST, r += CST;
		v.push_back({l, r});
	}
	
	n += CST;

	ll fans = 0;
	for (int i = 0; i < MAXN - k - 1; i++) {
		pll seg = {i, i + k - 1};
		ll ans = helper(seg);
		for (pll e : v) ans += I(seg, e);
		fans = max(fans, ans);	
	}

	cout << fans << endl;
	return 0;
}