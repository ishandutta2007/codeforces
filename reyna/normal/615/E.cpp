//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 0;

int read() { int x; cin >> x; return x; }

ll dx[6] = {-1, -2, -1, 1, 2, 1};
ll dy[6] = {2, 0, -2, -2, 0, 2};

ll c2(ll x) {
	return (x * (x - 1)) / 2;	
}

ll sum(ll l, ll r) {
	return c2(r + 1) - c2(l);	
}

ll area(ll x) {
	ll en = x * 2 - 1;
	return 	-en + sum(x, en) * 2;
}

void move(ll &x, ll &y, ll co, ll ti) {
	x += dx[co] * ti;
	y += dy[co] * ti;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long x;
	cin >> x;
	if (x == 0) {
		cout << 0 << ' ' << 0 << endl;
		return 0;	
	}
	x++;
	ll cx = 0, cy = 0;
	ll bl = 0, br = 1e9;
	while (bl < br - 1) {
		ll bm = (bl + br) >> 1;
		if (area(bm) <= x)
			bl = bm;
		else
			br = bm;
	}
	x -= area(bl);
	move(cx, cy, 4, bl - 1);
	while (x) {
		move(cx, cy, 5, min(x, 1LL));
		x -= min(x, 1LL);
		for (int i = 0; i < 6; ++i) {
			int step = i == 0? 1: 0;
			move(cx, cy, i, min(x, bl - step));
			x -= min(x, bl - step);
		}
		bl++;
	}
	cout << cx << ' ' << cy << endl;
	
	
	
}