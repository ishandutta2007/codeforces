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

	int l;
	cin >> l;

	vector<int> last(l + 1, 0);
	vector<int> n(l + 1);
	vector<LL> sum(l + 1);

	LL mx = (1ll << 32);
	auto check = [&](LL val)
	{
		if(val >= mx)
		{
			cout << "OVERFLOW!!!\n";
			exit(0);
		}
	};

	for(int i = 1; i <= l; i++)
	{
		DB(i, last[i], sum[0]);
		if(last[i] != 0 && i != l) last[i + 1] = last[i];

		string str;
		cin >> str;
		if(str == "for")
		{
			cin >> n[i];
			last[i + 1] = i;
		}

		if(str == "add")
		{
			int id = last[i];
			sum[id]++;
			check(sum[id]);
		}

		if(str == "end")
		{
			int id = last[i];
			sum[last[id]] += sum[id] * n[id];
			check(sum[last[id]]);
			if(i != l) last[i + 1] = last[id];
		}
	}

	DB(sum);
	cout << sum[0] << "\n";
}