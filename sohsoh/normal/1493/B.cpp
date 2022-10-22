#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

pll CV(int t) {
	return {t / 10, t % 10};
}

string S(int x) {
	if (x / 10) return to_string(x);
	else return "0" + to_string(x);
}

int CV(pll e) {
	return 10 * e.X + e.Y;
}

int R(int t) {
	if (t == 0 || t == 1 || t == 8) return t;
	if (t == 2) return 5;
	if (t == 5) return 2;
	return -1;
}

pll R(pll e) {
	int d1 = e.X, d2 = e.Y;
	return {R(d2), R(d1)};	
}

pair<pll, pll> R(pair<pll, pll> e) {
	return {R(e.Y), R(e.X)};
}

inline int solve() {
	int h, m, hh, mm;
	scanf("%d %d", &h, &m);
	scanf("%d:%d", &hh, &mm);
	
	while (true) {
		pll tm = CV(mm), th = CV(hh);
		pll rm = R({th, tm}).Y, rh = R({th, tm}).X;
		if (rm.X != -1 && rm.Y != -1 && rh.X != -1 && rh.Y != -1 && CV(rm) < m && CV(rh) < h) {	
			printf("%s:%s \n", S(CV(CV(hh))).c_str(), S(CV(CV(mm))).c_str());
			break;
		}

		mm++;
		if (mm == m) {
			mm = 0;
			hh++;
			hh %= h;
		}
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}