#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
struct line {
	ll m;
	ll b;
	ll xpoint;
	line(ll x, ll y) {
		m = x;
		b = y;
	}
	line(){}
};


const ll MAXA = 1000000000;
const ll inf = 1LL << 60;
const int MAXN = 100100;

int N;

int head = 0;
int tail = 0;
line convex[MAXN];
ll dp[MAXN];

ll A[MAXN];
ll B[MAXN];

ll eval(line &l, ll x) {
	return l.m * x + l.b;
}

ll get(ll x) {
	while (head + 1 < tail && convex[head + 1].xpoint <= x) {
		++head;
	}
	return eval(convex[head], x);
}

ll getx(line &cur, line &prv) {
	ll lo = prv.xpoint;
	ll hi = MAXA;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (eval(cur, mid) < eval(prv, mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

bool better(line &cur, line &oth) {
	ll x = oth.xpoint;
	return eval(cur, x) < eval(oth, x);
}

void put(line l) {
	while (head < tail && better(l, convex[tail - 1])) {
		--tail;
	}
	if (head == tail) {
		l.xpoint = 0;
	} else {
		l.xpoint = getx(l, convex[tail - 1]);
	}
	convex[tail] = l;
	++tail;


}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for(int i = 1; i <= N; ++i) {
		cin >> B[i];
	}

	put(line(A[N], 0));
	for(int i = N - 1; i > 0; --i) {
		ll best = get(B[i]);
		dp[i] = best;
		put(line(A[i], dp[i]));
	}

	ll ans = dp[1];
	cout << ans << "\n";
}