#include <bits/stdc++.h>
using namespace std;

using db = double;

const int N = 11;

struct ball {
	db x, v, m;
	int id;
	bool operator <(ball b) const {
		return x < b.x;
	}
}b[N];

db ans[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; db t; cin >> n >> t;
	for(int i = 1; i <= n; i ++) {
		cin >> b[i].x >> b[i].v >> b[i].m;
		b[i].id = i;
	}
	sort(b + 1, b + n + 1);

	while(1) {
		db nxt = 25252; int j = 0;
		for(int i = 1; i < n; i ++) if(b[i].v > b[i + 1].v) {
			db t = (b[i + 1].x - b[i].x) / (b[i].v - b[i + 1].v);
			if(t < nxt) {
				nxt = t;
				j = i;
			}
		}
		if(nxt > t) break;
		for(int i = 1; i <= n; i ++)
			b[i].x += b[i].v * nxt;
		db nv1 = ((b[j].m - b[j + 1].m) * b[j].v + 2 * b[j + 1].m * b[j + 1].v) / (b[j].m + b[j + 1].m);
		db nv2 = -(b[j + 1].v - b[j].v) + nv1;
		b[j].v = nv1; b[j + 1].v = nv2;
		t -= nxt;
	}
	for(int i = 1; i <= n; i ++)
			b[i].x += b[i].v * t;

	for(int i = 1; i <= n; i ++)
		ans[b[i].id] = b[i].x;
	cout << fixed << setprecision(9);
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << '\n';
}