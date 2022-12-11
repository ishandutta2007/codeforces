#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) for(int i = 0; i < a; i++)
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;

template<class L, class R> ostream& operator<<(ostream &ost, pair<L, R> p)
{
	return ost << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> ostream& operator<<(ostream &ost, vector<T> &vec)
{
	ost << "{";
	REP(i, vec.size()) ost << (i == 0 ? "" : ", ") << vec[i];
	return ost << "}";
}

template<class T> void dump(const char *s, T a) { cerr << s << ": " << a << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{
	while(*s != ',') cerr << *s++;
	cerr << ": " << a;
	dump(s + 1, x...);
}

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__)
#else
#define DB(...)
#endif

LL get_kth(vector<LL> x, vector<LL> rec, LL k) {
	LL mod = 1e9 + 6;
	int n = rec.size();
	for(LL &x : rec) x = (x + mod) % mod;
	auto combine = [&](vector<LL> a, vector<LL> b) {
		vector<LL> ret(n * 2 + 1);
		REP(i, n + 1) REP(j, n + 1)
			ret[i + j] = (ret[i + j] + a[i] * b[j]) % mod;
		for(int i = 2 * n; i > n; i--) REP(j, n)
			ret[i - j - 1] = (ret[i - j - 1] + ret[i] * rec[j]) % mod;
		ret.resize(n + 1);
		return ret;
	};

	vector<LL> r(n + 1), pw(n + 1);
	r[0] = 1, pw[1] = 1;

	for(++k; k; k /= 2) {
		if(k % 2) r = combine(r, pw);
		pw = combine(pw, pw);
	}

	LL ret = 0;
	REP(i, n) ret = (ret + r[i + 1] * x[i]) % mod;
	return ret;
}

LL fpow(LL a, LL n, LL mod = 1e9 + 7)
{
	if(n == 0) return 1;
	if(n % 2 == 1) return (a * fpow(a, n - 1)) % mod;
	LL x = fpow(a, n / 2);
	return (x * x) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	vector<LL> f1(3), f2(3), f3(3), C(5);
	f1[0] = 1;
	f2[1] = 1;
	f3[2] = 1;
	C[3] = 2;
	C[4] = 6;

	vector<LL> rf = {1, 1, 1};
	vector<LL> rC = {3, -2, 0, -1, 1};

	LL n, c;
	LL f_1, f_2, f_3;
	cin >> n >> f_1 >> f_2 >> f_3 >> c;

	LL F1 = get_kth(f1, rf, n - 1);
	LL F2 = get_kth(f2, rf, n - 1);
	LL F3 = get_kth(f3, rf, n - 1);
	LL CC = get_kth(C, rC, n - 1);

	LL mod = 1e9 + 7;
	LL ans = fpow(f_1, F1) % mod;
	ans = (ans * fpow(f_2, F2)) % mod;
	ans = (ans * fpow(f_3, F3)) % mod;
	ans = (ans * fpow(c, CC)) % mod;
	cout << ans << "\n";
}