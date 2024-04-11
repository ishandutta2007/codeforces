#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef long long ll;

struct line {
	ll m;
	ll b;
	ll xpoint;
	line (ll mm, ll bb) {
		m = mm;
		b = bb;
	}
	line() {}
};

const int MAXN = 100100;
const int MAXP = 110;
const int MAXT = 1000000100;

int H[MAXN];
int T[MAXN];
ll D[MAXN];
map<int, int> at;

ll times[MAXN];
ll cnts[MAXN];

ll A[MAXN]; // prefix sums of cnt
ll B[MAXN]; // prefix sum of cnt * times
ll dp[MAXN][MAXP];

line v[MAXN];
int head = 0;
int tail = 0;

ll eval(line &l, ll &x) {
	return l.m * x + l.b;
}

ll get(ll x) {
	while (head < tail && v[head].xpoint <= x) {
		++head;
	}
	--head;
	return eval(v[head], x);
}

ll findx(line &prv, line &cur) {
	ll num = cur.b - prv.b;
	ll denom = prv.m - cur.m;
	ll x = (num + denom - 1) / denom;
	return x;
}

bool better(line &a, line &b) {
	ll x = b.xpoint;
	return eval(a, x) <= eval(b, x);
}

void insert(line l) {
	while (better(l, v[tail - 1])) {
		--tail;
	}
	line &prv = v[tail - 1];
	l.xpoint = findx(prv, l);
	v[tail] = l;
	++tail;
}

void reset() {
	line first(0, 0);
	first.xpoint = -MAXT;
	head = 0;
	tail = 1;
	v[0] = first;
}

int N, M, P;
int main() {
	scanf("%d %d %d", &N, &M, &P);

	for(int i = 2; i <= N; ++i) {
		cin >> D[i];
		D[i] += D[i - 1];
	}

	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = D[a];
		b -= a;
		++at[b];
	}

	int idx = 0;
	repi(i, at) {
		times[idx] = i->first;
		cnts[idx] = i->second;
		ll prod = times[idx] * cnts[idx];
		A[idx + 1] = A[idx] + cnts[idx];
		B[idx + 1] = B[idx] + prod;
		++idx;
	}

	for(int i = 1; i <= idx; ++i) {
		ll val = A[i] * times[i - 1];
		val -= B[i];
		dp[i][1] = val;
	}

	for(int p = 1; p < P; ++p) {
		reset();
		for(int i = 1; i <= idx; ++i) {
			ll m = -A[i];
			ll b = dp[i][p] + B[i];
			insert(line(m, b));

			ll ipart = times[i - 1] * A[i] - B[i];
			ll jpart = get(times[i - 1]);
			dp[i][p + 1] = jpart + ipart;
		}
	}

	ll ans = dp[idx][P];
	cout << ans << "\n";
	return 0;
}