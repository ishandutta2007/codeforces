#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

const int N = 256;

int encode(string s) {
	int x = 0;
	rep(i, 8) if (s[i] == '1') x |= 1<<i;
	return x;
}

bool updated;

void f(string& s, string t) {
	int n = s.length(), m = t.length();
	if (!n || n > m || (n == m && s > t))
		s = t, updated = true;
}

int main() {
	vector<string> F(N), T(N), E(N);
	F[encode("00001111")] = "x";
	F[encode("00110011")] = "y";
	F[encode("01010101")] = "z";
	for (;;) {
		updated = false;
		rep(x, N) if (!F[x].empty()){
			int y = x ^ (N - 1);
			f(F[y], "!" + F[x]);
		}
		rep(x, N) if (!E[x].empty()) {
			int y = x;
			f(F[y], "(" + E[x] + ")");
		}
		rep(x, N) if (!F[x].empty()){
			int y = x;
			f(T[y], F[x]);
		}
		rep(x, N) rep(_x, N) if (!T[x].empty() && !F[_x].empty()){
			int y = x & _x;
			f(T[y], T[x] + "&" + F[_x]);
		}
		rep(x, N) if (!T[x].empty()){
			int y = x;
			f(E[y], T[x]);
		}
		rep(x, N) rep(_x, N) if (!E[x].empty() && !T[_x].empty()){
			int y = x | _x;
			f(E[y], E[x] + "|" + T[_x]);
		}
		if (!updated) break;
	}
	// rep(x, N) cout << E[x] << endl;
	int Q; cin >> Q;
	while (Q--) {
		string s; cin >> s;
		int x = encode(s);
		cout << E[x] << endl;
	}
}