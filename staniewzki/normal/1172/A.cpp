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

	int n;
	cin >> n;

	vector<int> turn(n + 1);
	vector<int> a(n), b(n);
	REP(i, n)
	{
		cin >> a[i];
		turn[a[i]] = 0;
	}

	REP(i, n)
	{
		cin >> b[i];
		turn[b[i]] = i + 1;
	}

	int pos = 0;
	bool can_continue = true;
	REP(i, n)	
	{
		if(b[i] == pos + 1)
			pos++;
		else if(pos != 0)
		{
			can_continue = false;
			break;
		}
	}

	DB(pos, can_continue);
	if(can_continue)
	{
		int t = 1;
		bool ok = true;
		for(int i = pos + 1; i <= n; i++)
		{
			DB(turn[i], t);
			if(turn[i] >= t)
				ok = false;
			t++;
		}

		if(ok)
		{
			cout << t - 1 << "\n";
			return 0;
		}
	}

	int ans = 0;
	FOR(i, 1, n)
	{
		DB(turn[i], i, turn[i] - i + 1);
		ans = max(ans, turn[i] - i + 1);
	}

	cout << ans + n << "\n";
}