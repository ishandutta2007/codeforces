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
 	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> first(n + 1, -1), last(n + 1, -1);
	REP(i, k)
	{
		int a;
		cin >> a;
		if(first[a] == -1) first[a] = i;
		last[a] = i;
	}

	int sum = 0;
	FOR(i, 1, n) for(int j = i - 1; j <= i + 1; j++)
	{
		if(j != 0 && j != n + 1)
		{
			int x = first[i];
			int y = last[j];
			if(x == -1 || y == -1 || x > y)
				sum++;
		}
	}

	cout << sum << "\n";
}