#include <bits/stdc++.h>
using namespace std;

#define left left233

using ll = long long;
const int N = 1e5L + 11;

struct poi {
	ll x, y;
}p[N], q[N];

ll a, b, c, d;
bool down(poi p, poi q) {
	return p.y * b + (q.x - p.x) * a < q.y * b;
}
bool left(poi p, poi q) {
	return p.x * c + (q.y - p.y) * d < q.x * c;
}

int dp[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	char _;
	cin >> a >> _ >> b;
	cin >> c >> _ >> d;
	for(int i = 0; i < n; i ++) {
		cin >> p[i].x >> p[i].y;
		if(!left(poi{0, 0}, p[i]) || !down(poi{0, 0}, p[i])) {
			n --;
			i --;
		}
	}
	sort(p, p + n, left);

	int top = 0;
	for(int i = 0; i < n; i ++) {
		int m = i;
		while(m + 1 < n && !left(p[i], p[m + 1]))
			m ++;
		for(int j = i; j <= m; j ++) {
			int l = 0, r = top + 1;
			while(l + 1 < r) {
				int bm = (l + r) / 2;
				if(down(q[bm], p[j]))
					l = bm;
				else
					r = bm;
			}
			dp[j] = l + 1;
		}
		for(int j = i; j <= m; j ++)
			if(dp[j] == top + 1)
				q[++ top] = p[j];
			else if(down(p[j], q[dp[j]]))
				q[dp[j]] = p[j];
		i = m;
	}
	cout << top << '\n';
}