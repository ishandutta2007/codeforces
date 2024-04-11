#include <cstdio>
#include <map>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void wt(int x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

void exgcd(int a, int b, int &x, int &y) {
	if (!b) { x = 1, y = 0; return; }
	exgcd(b, a % b, x, y);
	int t = x;
	x = y, y = t - a / b * y;
}

const int N = 2e5 + 10;

struct Pt{
	int bel, pos, id;
	Pt(int a = 0, int b = 0, int c = 0) : bel(a), pos(b), id(c) {}
	bool operator < (const Pt &t) const {
		return bel < t.bel || (bel == t.bel && pos < t.pos);
	}
} c[N];
map <int, int> mp;
int T, n, a[N], ans[N], S, cnt;
	
int main() {
	T = rd(), n = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd(), S = (S + a[i]) % T;
	int t = -a[1];
	for (int i = 1; i <= n; i ++) {
		t = (t + a[i]) % T;
	 	if (!mp[t]) mp[t] = i;
	}
	int g = __gcd(S, T), len = T / g, step = S / g, inv, y;
	//printf("%d %d %d\n", S, T, g);
	t = -a[1], exgcd(step, len, inv, y);
	inv = (inv + len) % len;
	for (int i = 1; i <= n; i ++) {
		t = (t + a[i]) % T;
		if (mp[t] == i) c[++cnt] = Pt(t % g, 1ll * (t / g) * inv % len, i);
	}
	sort(c + 1, c + cnt + 1);
	for (int i = 1; i <= cnt; i ++) {
		int j = i;
		while (j < cnt && c[j + 1].bel == c[i].bel) j ++;
		//printf("%d\n", j);
		for (int k = i; k < j; k ++) ans[c[k].id] += c[k + 1].pos - c[k].pos;
		ans[c[j].id] += c[i].pos + len - c[j].pos;
		i = j;
	}
	for (int i = 1; i <= n; i ++) wt(ans[i]), putchar(32); puts("");
	return 0;
}