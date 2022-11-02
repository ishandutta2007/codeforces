#include<bits/stdc++.h>

#define NN 6011
using namespace std;
using INT = long long;
using pii = pair<int, int>;

struct point{
	int x, y;
	point(int x = 0, int y = 0) : x(x), y(y) {}
	void input() {
		scanf("%d %d", &x, &y);
	}
	point operator - (point u) {
		return point(x - u.x, y - u.y);
	}
} p[NN];

int cnt[2][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		p[i].input();
		p[i].x >>= 1;
		p[i].y >>= 1;
	}
	INT ans = 0;
	
	for(int i = 1; i <= n; i ++) {
		memset(cnt, 0, sizeof cnt);
		for(int j = i + 1; j <= n; j ++) {
			point d = p[i] - p[j];
			cnt[abs(d.x) & 1][abs(d.y) & 1] ++;
		}
		
		for(int j = 0; j < 2; j ++) {
			for(int k = 0; k < 2; k++) {
				ans += (INT)(cnt[j][k] - 1) * cnt[j][k] / 2;
			}
		}

		ans += (INT)cnt[0][0] * (cnt[0][1] + cnt[1][0] + cnt[1][1]);
	}
	cout << ans << endl;
}