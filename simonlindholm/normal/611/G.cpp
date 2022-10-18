#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const ll mod = 1000000007;

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<ll> x, y;
	x.reserve(N*3);
	y.reserve(N*3);
	x.resize(N);
	y.resize(N);
	rep(i,0,N) {
		cin >> y[i] >> x[i];
	}
	rep(i,0,N) x.push_back(x[i]), y.push_back(y[i]);
	rep(i,0,N) x.push_back(x[i]), y.push_back(y[i]);
	ll A = 0;
	rep(i,0,N) {
		A += x[i] * y[i+1] - x[i+1] * y[i];
	}

	ll a = 0, a2 = 0;
	vector<ll> xy(2*N), rxy(2*N), sumxy(2*N), sumx(2*N), sumy(2*N);
	ll sxy = 0, sx = 0, sy = 0;
	rep(k,0,2*N) {
		sumxy[k] = sxy;
		sumx[k] = sx;
		sumy[k] = sy;
		rxy[k] = a2;
		xy[k] = a;
		sxy += rxy[k]; sxy %= mod;
		sx += x[k]; sx %= mod;
		sy += y[k]; sy %= mod;
		a += x[k] * y[k+1] - x[k+1] * y[k];
		a2 += x[k] * y[k+1] - x[k+1] * y[k];
		a2 %= mod;
	}

	ll res = 0;
	rep(i,0,N) {
		int lo = 1, hi = N-1;
		auto works = [&](int it) {
			int j = i + it;
			ll a = xy[j] - xy[i];
			a += x[j] * y[i] - x[i] * y[j];
			return a <= A/2;
		};
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (works(mid)) lo = mid;
			else hi = mid;
		}

		int count = (lo + 1 - 2);
		res += count * (A % mod) % mod;
		res += 2*count * rxy[i] % mod;
		int start = i + 2;
		int end = i + lo+1;
		res -= 2*(sumxy[end] - sumxy[start]);
		res -= 2*(sumx[end] - sumx[start]) * y[i] % mod;
		res += 2*(sumy[end] - sumy[start]) * x[i] % mod;
		res %= mod;
	}

	if (res < 0) res += mod;
	cout << res << endl;
}