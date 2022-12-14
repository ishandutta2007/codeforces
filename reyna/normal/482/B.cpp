//In the name of God
/*
Even if I see the illusion I want to see 
No matter how many times I close my eyes, I am still unfulfilled
*/
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

int weed[N << 2], nut[N << 2], ql[N], qr[N], qv[N], n;

void sprout(int v, int l, int r) {
	weed[v] = weed[l] & weed[r];
}

void absorb(int v, int l, int r) {
	nut[l] |= nut[v];
	weed[l] |= nut[v];
	nut[r] |= nut[v];
	weed[r] |= nut[v];
	nut[v] = 0;
}

void water(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		weed[v] |= x;
		nut[v] |= x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	absorb(v, l, r);
	water(i, j, x, l, b, m);
	water(i, j, x, r, m, e);
	sprout(v, l, r);
}

int smoke(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return (1 << 30) - 1;
	if (i <= b && e <= j)
		return weed[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	absorb(v, l, r);
	return smoke(i, j, l, b, m) & smoke(i, j, r, m, e);	
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	int m = read();
	for (int i = 0; i < m; ++i) {
		ql[i] = read() - 1, qr[i] = read(), qv[i] = read();
		water(ql[i], qr[i], qv[i]);	
	}
	for (int i = 0; i < m; ++i)
		if (smoke(ql[i], qr[i]) != qv[i])
			return cout << "NO\n", 0;
	cout << "YES\n";	
	for (int i = 0; i < n; ++i)
		cout << smoke(i, i + 1) << ' ';
	
}