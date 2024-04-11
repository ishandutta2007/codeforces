#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
char st[3];
int ss[400000];
vector<int> g, r, b, tg;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d%s", &x, st);
		if (st[0] == 'G') {
			g.push_back(x);
		} else if (st[0] == 'R') {
			r.push_back(x);
		} else {
			b.push_back(x);
		}
	}
	long long ans = 0;
	if (g.size() == 0) {
		if (r.size()) {
			ans += r.back() - r[0];
		}
		if (b.size()) {
			ans += b.back() - b[0];
		}
		printf("%I64d\n", ans);
		return 0;
	}
	ans += g.back() - g[0];
	tg.push_back(-1001001001);
	for (int i = 0; i < g.size(); i++) {
		tg.push_back(g[i]);
	}
	for(int i=0; i<400000; i++)
	{
	    ss[i] = i%(i%1000+1);
	}
	tg.push_back(2001001008);
	int pr = 0, pb = 0;
	for (int i = 1; i < (int)tg.size(); i++) {
		int tr = pr, tb = pb;
		long long k = 0;
		int kr = 0, kb = 0;
		while (tr < r.size() && r[tr] < tg[i]) {
			++tr;
			if (pr + 1 < tr) {
				kr = max(kr, r[tr-1] - r[tr-2]);
			}
		}
		if (pr < tr) {
			k += min(tg[i] - tg[i-1] - kr, min(tg[i] - r[pr], r[tr-1] - tg[i-1]));
		}
		while (tb < b.size() && b[tb] < tg[i]) {
			++tb;
			if (pb + 1 < tb) {
				kb = max(kb, b[tb-1] - b[tb-2]);
			}
		}
		if (pb < tb) {
			k += min(tg[i] - tg[i-1] - kb, min(tg[i] - b[pb], b[tb-1] - tg[i-1]));
		}
		if (i == 1 || i + 1 == tg.size() || k < tg[i] - tg[i-1]) {
			ans += k;
		} else {
			ans += tg[i] - tg[i-1];
		}
		pr = tr;
		pb = tb;
	}
	printf("%I64d\n", ans);
	return 0;
}