#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 100000;

struct Input {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
			--a[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int l, r;
	
	int bad[N];
	int sum[N + 1];
	int cnt1[N], cnt2[N], cnt3[N], cnt4[N];
	
	int bad2, bad3, bad3_, bad4, bad4_;
	
	int cntbad2 (int x) {
		return cnt1[x] != cnt2[x];
	}
	
	int cntbad3 (int x) {
		return cnt1[x] < cnt3[x];
	}
	
	int cntbad3_ (int x) {
		return (cnt1[x] - cnt3[x]) % 2 != 0;
	}
	
	int cntbad4 (int x) {
		return cnt1[x] < cnt4[x];
	}
	
	int cntbad4_ (int x) {
		return (cnt1[x] - cnt4[x]) % 2 != 0;
	}
	
	bool check () {
		if (r <= n / 2) {
			return sum[l] == 0 && sum[n - r] - sum[r] == 0 && bad2 == 0;
		}
		if (n - l <= n / 2) {
			return sum[n - r] == 0 && sum[l] - sum[n - l] == 0 && bad2 == 0;
		}
		if (l < n - r) {
			return sum[l] == 0 && bad3 == 0 && bad3_ <= 1;
		} else {
			return sum[n - r] == 0 && bad4 == 0 && bad4_ <= 1;
		}
	}
	
	void solve () {
		ans = 0;
		bad2 = bad3 = bad3_ = bad4 = bad4_ = 0;
		sum[0] = 0;
		forn (i, n) {
			bad[i] = a[i] != a[n - 1 - i];
			sum[i + 1] = sum[i] + bad[i];
		}
		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);
		memset(cnt3, 0, sizeof cnt3);
		memset(cnt4, 0, sizeof cnt4);
		forn (i, n) {
			cnt3[a[i]]++;
			cnt4[a[i]]--;
		}
		forn (i, n) {
			bad2 += cntbad2(i);
			bad3 += cntbad3(i);
			bad3_ += cntbad3_(i);
			bad4 += cntbad4(i);
			bad4_ += cntbad4_(i);
		}
		r = 0;
		for (l = 0; l < n; ++l) {
			while (r <= l || !check()) {
				if (r == n) {
					return;
				}
				bad2 -= cntbad2(a[r]);
				bad3 -= cntbad3(a[r]);
				bad3_ -= cntbad3_(a[r]);
				bad4 -= cntbad4(a[r]);
				bad4_ -= cntbad4_(a[r]);
				if (bad[r]) {
					bad2 -= cntbad2(a[n - 1 - r]);
					bad3 -= cntbad3(a[n - 1 - r]);
					bad3_ -= cntbad3_(a[n - 1 - r]);
					bad4 -= cntbad4(a[n - 1 - r]);
					bad4_ -= cntbad4_(a[n - 1 - r]);
				}
				cnt1[a[r]]++;
				cnt2[a[n - 1 - r]]++;
				cnt3[a[r]]--;
				cnt4[a[n - 1 - r]]++;
				bad2 += cntbad2(a[r]);
				bad3 += cntbad3(a[r]);
				bad3_ += cntbad3_(a[r]);
				bad4 += cntbad4(a[r]);
				bad4_ += cntbad4_(a[r]);
				if (bad[r]) {
					bad2 += cntbad2(a[n - 1 - r]);
					bad3 += cntbad3(a[n - 1 - r]);
					bad3_ += cntbad3_(a[n - 1 - r]);
					bad4 += cntbad4(a[n - 1 - r]);
					bad4_ += cntbad4_(a[n - 1 - r]);
				}
				++r;
			}
			debug(mp(l, r));
			ans += n - r + 1;
			bad2 -= cntbad2(a[l]);
			bad3 -= cntbad3(a[l]);
			bad3_ -= cntbad3_(a[l]);
			bad4 -= cntbad4(a[l]);
			bad4_ -= cntbad4_(a[l]);
			if (bad[l]) {
				bad2 -= cntbad2(a[n - 1 - l]);
				bad3 -= cntbad3(a[n - 1 - l]);
				bad3_ -= cntbad3_(a[n - 1 - l]);
				bad4 -= cntbad4(a[n - 1 - l]);
				bad4_ -= cntbad4_(a[n - 1 - l]);
			}
			cnt1[a[l]]--;
			cnt2[a[n - 1 - l]]--;
			cnt3[a[n - 1 - l]]--;
			cnt4[a[l]]++;
			bad2 += cntbad2(a[l]);
			bad3 += cntbad3(a[l]);
			bad3_ += cntbad3_(a[l]);
			bad4 += cntbad4(a[l]);
			bad4_ += cntbad4_(a[l]);
			if (bad[l]) {
				bad2 += cntbad2(a[n - 1 - l]);
				bad3 += cntbad3(a[n - 1 - l]);
				bad3_ += cntbad3_(a[n - 1 - l]);
				bad4 += cntbad4(a[n - 1 - l]);
				bad4_ += cntbad4_(a[n - 1 - l]);
			}
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}