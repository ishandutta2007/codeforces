#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#define debug(...) cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

bool ex[10];

int main() {
	int TC; cin >> TC;
	while (TC--) {
		rep(i, 10) ex[i] = 0;

		string s; cin >> s;
		int n = s.size();

		auto can = [&](int l) {
			rep(i, 10) {
				if (ex[i]) --l;
			}
			return l >= 0 and l % 2 == 0;
		};

		string ans = s;
		for (auto c : s) {
			ex[c - '0'] ^= 1;
		}

		bool f = 0;

		for (int i = n-1; i >= 0 && !f; --i) {
			ans.pop_back();
			int d = s[i] - '0';
			ex[d] ^= 1;

			for (int j = d-1; j >= 0; --j) {
				if (i == 0 && j == 0) {
					break;
				}
				ex[j] ^= 1;

				if (can(n-1-i)) {
					debug(ans, i, j);
					V<int> num(10);
					int rem = n-1-i;
					rep(t, 10) {
						if (ex[t]) {
							rem--;
							num[t]++;
						}
					}
					num[9] += rem;
					dump(num);

					ans.pb('0' + j);
					for (int t = 9; t >= 0; --t) {
						rep(tt, num[t]) {
							ans.pb('0' + t);
						}
					}
					f = 1;
					break;
				}
				ex[j] ^= 1;
			}
		}
		if (ans.size() == 0) {
			int l = n-1;
			if (l & 1) --l;
			ans = string(l, '9');
		}
		cout << ans << '\n';
	}
	return 0;
}