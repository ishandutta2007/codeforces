#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int fop, gop, hop;
int op(int a, int b, int c) {
	if (c == 0) return a&b;
	if (c == 1) return a|b;
	if (c == 2) return a^b;
	assert(0);
}
int F(int a, int b) { return op(a, b, fop); }
int G(int a, int b) { return op(a, b, gop); }
int H(int a, int b) { return op(a, b, hop); }

int go(int a, int b, int c, int d) {
	int e = F(a, b);
	int f = G(c, d);
	int g = H(b, c);
	int h = F(a, d);
	int i = H(e, f);
	int j = G(g, h);
	int k = F(i, j);
	return k;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	fop = 2, gop = 1, hop = 0;
	/*
	rep(i,0,3) rep(j,0,3) rep(k,0,3) {
		fop = i, gop = j, hop = k;
		if (go(0,1,1,0) == 0 && i != j && i != k && j != k) cout << i << ' ' << j << ' ' << k << endl;
	}
	*/
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << go(a,b,c,d) << endl;
}