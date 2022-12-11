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
	vector<int> per(n);
	vector<int> pos(n);
	REP(i, n)
	{
		cin >> per[i];	
		per[i]--;
		pos[per[i]] = i;
	}

	vector<PII> ops;
	auto swp = [&](int a, int b)
	{
		ops.EB(a, b);
		swap(per[a], per[b]);	
		pos[per[a]] = a;
		pos[per[b]] = b;
	};

	REP(i, n)
	{
		int x = pos[i];
		DB(i, x);
		if(x == i) continue;
		if(i < n / 2)
		{
			if(x < n / 2)
			{
				swp(x, n - 1);
				swp(i, n - 1);
			}
			else
			{
				if(i == 0) swp(0, x);
				else
				{
					if(x != n - 1)
					{
						swp(0, x);
						swp(0, n - 1);
						swp(i, n - 1);
						swp(0, x);
					}
					else
						swp(i, x);
				}
			}
		}
		else
		{
			swp(0, x);
			swp(0, i);
			swp(0, x);
		}
	
	}

	DB(per);

	cout << ops.size() << "\n";
	for(auto p : ops)
		cout << p.ST + 1 << " " << p.ND + 1 << "\n";
}