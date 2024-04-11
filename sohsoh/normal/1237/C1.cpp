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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct point {
	int x, y, z, ind;
	point() {}
	point(int tx, int ty, int tz) { x = tx, y = ty, z = tz; }
};

inline bool operator < (const point& p1, const point& p2) {
	if (p1.x < p2.x) return true;
	if (p1.x > p2.x) return false;
	if (p1.y < p2.y) return true;
	if (p1.y > p2.y) return false;
	if (p1.z < p2.z) return true;
	if (p1.z > p2.z) return false;
	return false;
}

set<point> st;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		point p;
		cin >> p.x >> p.y >> p.z;	
		p.ind = i;
		st.insert(p);
	}

	while (!st.empty()) {
		point p = *st.begin();
		st.erase(p);
		int x = st.lower_bound(p) -> x;
		
		auto it = st.lower_bound(point(x, p.y, -INF));
		if (it == st.end() || it -> x != x) it--;
		int y = it -> y;
		it = st.lower_bound(point(x, y, p.z));
		if (it == st.end() || it -> x != x || it -> y != y) it--;
		cout << p.ind << sep << it -> ind << endl;
		st.erase(it);
	}
	return 0;
}