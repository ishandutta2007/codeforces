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

mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) { return uniform_int_distribution<int>(a, b)(_gen); }

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<LL> sums1(n + 1), sums2(n + 1);
	vector<LL> w1(n + 1), w2(n + 1);

	FOR(i, 0, n) w1[i] = rd(1, 1000);
	FOR(i, 0, n) w2[i] = rd(1, 1000);

	auto get_len = [&](int a, int b)
	{
		if(a > b) b += n;
		return b - a + 1;
	};
	
	REP(i, m)
	{
		int a, b;
		cin >> a >> b;
		int len = min(get_len(a, b), get_len(b, a));
		sums1[a - 1] += w1[len];
		sums1[b - 1] += w1[len];
		sums2[a - 1] += w2[len];
		sums2[b - 1] += w2[len];
	}

	DB(sums1);
	DB(sums2);

	int m1 = 1000696969;
	int m2 = 1000000007;

	int base = rd(100, 2000);

	vector<LL> h1(n), h2(n);
	vector<LL> p1(n, 1), p2(n, 1);
	
	REP(j, n)
	{
		if(j != 0)
		{
			h1[j] = h1[j - 1] * base % m1;
			h2[j] = h2[j - 1] * base % m2;
			p1[j] = p1[j - 1] * base % m1;
			p2[j] = p2[j - 1] * base % m2;
		}

		h1[j] = (h1[j] + sums1[j] + 1) % m1;
		h2[j] = (h2[j] + sums2[j] + 1) % m2;
	}

	auto get_hash = [&](int l, int r) -> PII
	{
		if(l > r) return {0, 0};
		if(l == 0) return {h1[r], h2[r]};
		LL r1 = ((h1[r] - h1[l - 1] * p1[r - l + 1]) % m1 + m1) % m1;
		LL r2 = ((h2[r] - h2[l - 1] * p2[r - l + 1]) % m2 + m2) % m2;
		return {r1, r2};
	};

	for(int j = 1; j < n; j++)
	{
		if(get_hash(0, j - 1) == get_hash(n - j, n - 1) &&
		   get_hash(j, n - 1) == get_hash(0, n - j - 1))
		{
			DB(j);
			cout << "Yes\n";
			return 0;
		}
	}


	cout << "No\n";
}