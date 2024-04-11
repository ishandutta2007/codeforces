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

int main()
{
	ios_base::sync_with_stdio(0);

	vector<int> ret(4);
	REP(i, 4)
	{
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cin >> ret[i];		
	}

	vector<int> a = {4, 8, 15, 16, 23, 42};
	vector<int> p(6);
	REP(i, 6) p[i] = i;

	do
	{
		vector<int> x(6);
		REP(i, 6) x[i] = a[p[i]];

		bool good = true;
		REP(i, 4)
			if(x[i] * x[i + 1] != ret[i])
				good = false;

		if(good)
		{
			cout << "! ";
			REP(i, 6) cout << x[i] << " ";
			cout << endl;
			return 0;
		}
	}
	while(next_permutation(p.begin(), p.end()));
}