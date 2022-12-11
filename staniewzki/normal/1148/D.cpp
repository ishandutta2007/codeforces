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

	int n;
	cin >> n;
	vector<PII> p(n);
	REP(i, n)
		cin >> p[i].ST >> p[i].ND;

	vector<int> a1, a2;
	REP(i, n)
	{
		if(p[i].ST < p[i].ND) a1.EB(i);
		if(p[i].ST > p[i].ND) a2.EB(i);
	}

	sort(a1.begin(), a1.end(), [&](int i, int j)
	{
		if(p[i].ND > p[j].ST && p[j].ND > p[i].ST) return i < j;
		return p[i].ND > p[j].ST;
	});

	sort(a2.begin(), a2.end(), [&](int i, int j)
	{
		if(p[i].ND < p[j].ST && p[j].ND < p[i].ST) return i < j;
		return p[i].ND < p[j].ST;
	});

	vector<int> ans;
	if(a1.size() < a2.size()) ans = a2;
	else ans = a1;

	cout << ans.size() << "\n";
	for(int x : ans) cout << x + 1 << " ";
	cout << "\n";
}