#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; ++i)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ve vector
#define pa pair

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef ve<int> vi;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;

template<typename A, typename B> bool umx (A &a, B b) {if (a < b) {a = b; return 1;} return 0;}
template<typename A, typename B> bool umn (A &a, B b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;

int pr[N], p[N];

int Pr (int x) {
	return (pr[x] == x) ? x : (pr[x] = Pr(pr[x]));
}

int P (int x) {
	return (p[x] == x) ? x : (p[x] = P(p[x]));
}

int r = 0;

void uni (int x, int y) {
	x = P(x);
	y = P(y);
	if (r ^= 1) {
		swap(x, y);
	}
	p[x] = y;
}

int main () {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		pr[i] = i;
		p[i] = i;
	}
	forn (i, m) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		--t;
		--x;
		--y;
		if (t == 0) {
			uni(P(Pr(x)), P(Pr(y)));
		}
		if (t == 1) {
			if (x > y) {
				swap(x, y);
			}
			x = Pr(x);
			y = Pr(y);
			while (x != y) {
				pr[x] = x + 1;
				uni(x, Pr(x));
				x = Pr(x);
			}
		}
		if (t == 2) {
			if (P(Pr(x)) == P(Pr(y))) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}