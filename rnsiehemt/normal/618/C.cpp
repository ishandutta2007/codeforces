#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

struct P {
	ll x, y;
	P() : x(0), y(0) { }
	P(ll x, ll y) : x(x), y(y) { }
};

P operator-(P a, P b) {
	return P(a.x-b.x, a.y-b.y);
}
ll operator^(P a, P b) {
	return a.x*b.y - a.y*b.x;
}
ll ccw(P a, P b, P c) {
	return ((b-a)^(c-b));
}
bool collinear(P a, P b, P c) {
	return ((b-a)^(c-b)) == 0;
}
ll sq(ll a) {
	return a*a;
}
ll distsq(P a, P b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

int N, a, b, c;
P p[100005];

bool inside(P a, P b, P c, P q) {
	//printf("%lld %lld %lld", ccw(a, b, q), ccw(b, c, q), ccw(c, a, q));
	return (ccw(a, b, q) >= 0 && ccw(b, c, q) >= 0 && ccw (c, a, q) >= 0) ||
		(ccw(a, b, q) <= 0 && ccw(b, c, q) <= 0 && ccw (c, a, q) <= 0);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
	a = 0; b = 1;
	for (int i = 2; i < N; i++) if (distsq(p[a], p[i]) < distsq(p[a], p[b])) b = i;
	//b = 2;
	c = -1;
	for (int i = 1; i < N; i++) if (i != b) {
		if (!collinear(p[0], p[b], p[i])) {
			//printf("%d: ", i);
			if (c == -1 || inside(p[0], p[b], p[c], p[i])) {
				c = i;
			}
			//printf("\n");
		}
	}
	printf("%d %d %d\n", a+1, b+1, c+1);
}