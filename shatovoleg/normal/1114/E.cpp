#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((v)?(v)->s:0)
#define get_h(v) ((v)?(v)->h:0)

mt19937 rnd(1337);

int cnt = 0;

int ask(int t, int v) {
	++cnt;
	if (t == 0)
		cout << "? ";
	else
		cout << "> ";
	cout << v << endl;
	cin >> v;
	return v;
}

int main() {
	int n;
	cin >> n;
	int l = 0, r = 1e9;
	while (r - l > 1) {
		int c = (r + l) >> 1;
		if (ask(1, c))
			l = c;
		else
			r = c;
	}
	int mx = r;
	int g = 0;
	while (cnt < 55) {
		int v = ask(0, rnd() % n + 1);
		g = __gcd(mx - v, g);
	}
	cout << "! " << mx - g * (n - 1) << " " << g << endl;
}