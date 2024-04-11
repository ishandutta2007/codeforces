#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, T, q;
int p[200005], l[200005], c[200005];

lf inline calc(int x, int c) {
	if(!~c) return Inf;
	if(c >= l[x]) return 0;
	return 1.L * p[x] * l[x] / (c + l[x]) / (c + l[x] + 1);
}

lf inline get(int x) {
	return 1.L * p[x] * min(c[x], l[x]) / (min(c[x], l[x]) + l[x]);
}

struct newone {
	lf $;
	int x, c;
	newone(int x = 0, int c = -1) : x(x), c(c) { $ = calc(x, c); }
	bool inline operator < (const newone &n) const {
		return abs($ - n.$) > 1e-10 ? ($ < n.$) : (x < n.x);
	}
};

set<newone> s, t;
lf ans = 0;

void inline ins() {
	auto it = --t.end();
	int x = it->x;
	ans += it->$;
	s.erase(newone(x, c[x] - 1));
	s.insert(*it);
	t.erase(it);
	t.insert(newone(x, ++c[x]));
}

void inline rem() {
	auto it = s.begin();
	int x = it->x;
	ans -= it->$;
	t.erase(newone(x, c[x]));
	t.insert(*it);
	s.erase(it);
	s.insert(newone(x, --c[x] - 1));
}

int main() {
	scanf("%d%d%d", &n, &T, &q);
	cont(i, n) scanf("%d", p + i);
	cont(i, n) scanf("%d", l + i), s.insert(newone(i)), t.insert(newone(i, 0));
	while(T--) ins();
	cont(i, q) {
		int mode, x;
		scanf("%d%d", &mode, &x);
		t.erase(newone(x, c[x]));
		s.erase(newone(x, c[x] - 1));
		ans -= get(x);
		l[x] += 3 - mode * 2;
		t.insert(newone(x, c[x]));
		s.insert(newone(x, c[x] - 1));
		ans += get(x);
		while ((--t.end())->$ - 1e-10 > s.begin()->$) rem(), ins(); 
		printf("%.10lf\n", (double)ans);
	}
	return 0;
}