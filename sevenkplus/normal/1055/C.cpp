#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int ff(int la, int ra, int ta, int lb, int rb, int tb) {
	if (la >= ta) {
		return ff(la-ta, ra-ta, ta, lb, rb, tb);
	}
	if (ra >= ta) {
		return ff(la, ta-1, ta, lb, rb, tb) + ff(0, ra-ta, ta, lb, rb, tb);
	}
	int rs = min(ra, rb);
	int ls = max(la, lb);
	if (rs < ls) return 0;
	return rs-ls+1;
}

int main() {
	int la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;
	if (ta < tb) {
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	int g = __gcd(ta, tb);
	int aa = la/g;
	la -= aa*g;
	ra -= aa*g;
	int bb = lb/g;
	lb -= bb*g;
	rb -= bb*g;
	int S = 0;
	S = max(S, ff(la, ra, ta, lb, rb, tb));
	S = max(S, ff(la+g, ra+g, ta, lb, rb, tb));
	S = max(S, ff(la+ta-g, ra+ta-g, ta, lb, rb, tb));
	cout << S << endl;
	return 0;
}