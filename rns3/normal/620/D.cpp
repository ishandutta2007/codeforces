#include <bits/stdc++.h>
using namespace std;
#define M 3000
#define N 3000000
typedef long long ll;
ll ABS(ll u) {return u < 0 ? -u : u;}
ll dist(ll a, ll b) {return ABS(a - b);}

int n;
ll a[M], sa;
int m;
ll b[M], sb;

int na;
struct pnt{
	ll s;
	int i, j;
	pnt(ll s = 0, int i = 0, int j = 0) : s(s), i(i), j(j){}
}A[N];
bool operator<(pnt a, pnt b) {
	return a.s < b.s;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
		sa += a[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%I64d", &b[i]);
		sb += b[i];
	}

	ll delta = ABS(sa - sb);
    int I = 0, J = 0;
    int X = 0, Y = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		ll d = dist(sa - a[i] + b[j], sb - b[j] + a[i]);
		if (d < delta) {
			delta = d;
			J = i;
			Y = j;
		}
	}

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		A[na++] = pnt(a[i] + a[j], i, j);
	}
    sort(A, A + na);

    ll one = sa + sb >> 1;
    ll sum = sa + sb;

	for (int x = 1; x <= m; x++) for (int y = x + 1; y <= m; y++) {
		ll B = sb - b[x] - b[y];
		int c = lower_bound(A, A + na, pnt(one - B, 0, 0)) - A;
		if (c < na) {
			ll newB = B + A[c].s;
			ll d = ABS(newB * 2 - sum);
			if (d < delta) {
				delta = d;
				X = x, Y = y;
				I = A[c].i, J = A[c].j;
			}
		}
		--c;
		if (c >= 0) {
			ll newB = B + A[c].s;
			ll d = ABS(newB * 2 - sum);
			if (d < delta) {
				delta = d;
				X = x, Y = y;
				I = A[c].i, J = A[c].j;
			}
		}
	}
	printf("%I64d\n", delta);
	int k = !!I + !!J;
	printf("%d\n", k);
	if (I) {
		printf("%d %d\n", I, X);
	}
	if (J) {
		printf("%d %d\n", J, Y);
	}
	return 0;
}