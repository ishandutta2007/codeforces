#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class Fn>
void eachDivisor(vi& F, Fn fun, int num = 1, int mul = 1, int ind = 0) {
	if (ind == sz(F)) fun(mul, num);
	else {
		eachDivisor(F, fun, num, mul, ind+1);
		eachDivisor(F, fun, num * F[ind], -mul, ind+1);
	}
}

int main() {
	cin.sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vi as(N);
	vector<vi> fs(N);
	vi fc(1000000);
	rep(i,0,N) {
		int a;
		cin >> a;
		vi f;
		if (a % 2 == 0) {
			f.push_back(2);
			while (a % 2 == 0) a >>= 1;
		}
		for (int p = 3; p*p <= a; p += 2) {
			if (a % p == 0) {
				f.push_back(p);
				do a /= p; while (a % p == 0);
			}
		}
		if (a > 1) f.push_back(a);
		fs[i] = f;
		as[i] = a;
	}
	vi on(N);
	int count = 0;
	ll res = 0;
	rep(iter,0,Q) {
		int x;
		cin >> x, x--;
		bool o = on[x];
		if (o) count--;

		int r = 0;
		vi& F = fs[x];
		eachDivisor(F, [&](int mul, int num) {
			if (o) fc[num]--;
			r += fc[num] * mul;
			if (!o) fc[num]++;
		});

		if (o)
			res -= r;
		else
			res += r;

		if (!o) count++;
		on[x] = !o;
		cout << res << '\n';
	}
}