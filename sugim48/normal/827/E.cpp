#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <cassert>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef vector<int> vi;
struct edge { int v; ll w; };

const int MOD = 1000000007;
double EPS = 1e-10;
ll INF = INT_MAX;

struct C {
public:
	double x, y;
	C() {}
	C(double x, double y) : x(x), y(y) {}
	C operator + (C z) { return C(x + z.x, y + z.y); }
	C operator - (C z) { return C(x - z.x, y - z.y); }
	C operator * (double a) { return C(x * a, y * a); }
	C operator / (double a) { return C(x / a, y / a); }
	C operator * (C z) { return C(x * z.x - y * z.y, x * z.y + y * z.x); }
};
C conj(C z) { return C(z.x, -z.y); }

const int M = 1 << 20;
C unko[M];

void FFT(int N, C* a) {
	C* _a = new C[N];
	bool swapped = false;
	for (int n = 2; n <= N; n *= 2) {
		int m = N / n;
		rep(i, n / 2) {
			C z = unko[M / n * i];
			rep(j, m) {
				C x = a[(i * 2) * m + j];
				C y = a[(i * 2 + 1) * m + j] * z;
				_a[i * m + j] = x + y;
				_a[i * m + j + N / 2] = x - y;
			}
		}
		swap(a, _a);
		swapped = !swapped;
	}
	if (swapped) {
		swap(a, _a);
		rep(i, N) a[i] = _a[i];
	}
	delete[] _a;
}

void inv_FFT(int N, C* a) {
	rep(i, N) a[i] = conj(a[i]);
	FFT(N, a);
	rep(i, N) a[i] = conj(a[i]), a[i] = a[i] / (double)N;
}

void convolute(int N, C* a, C* b) {
	FFT(N, a); FFT(N, b);
	rep(i, N) a[i] = a[i] * b[i];
	inv_FFT(N, a);
}

char c[505050];

int main() {
	rep(i, M) {
		double theta = 2 * M_PI * i / M;
		unko[i] = C(cos(theta), sin(theta));
	}
	int T; cin >> T;
	while (T--) {
		int N; scanf("%d", &N);
		string s; scanf("%s", c); s = c;
		int _N;
		for (_N = 1; _N < N * 2 + 10; _N *= 2);
		C* a = new C[_N];
		C* b = new C[_N];
		rep(i, _N) a[i] = b[i] = C(0, 0);
		rep(i, N) {
			if (s[i] == 'V') a[i] = C(1, 0);
			if (s[i] == 'K') b[N - i] = C(1, 0);
		}
		convolute(_N, a, b);
		// rep(i, _N) cout << a[i].x << endl;
		vector<bool> pos(N + 1, true);
		rep(i, N * 2) if (a[i].x > 0.5) {
			int d = abs(i - N);
			for (int t = 1; t * t <= d; t++)
				if (d % t == 0)
					pos[t] = pos[d / t] = false;
		}
		vector<int> ans;
		for (int t = 1; t <= N; t++)
			if (pos[t])
				ans.pb(t);
		printf("%d\n", ans.size());
		for (int t: ans) printf("%d ", t);
		printf("\n");
	}
}