#include<bits/stdc++.h>
using namespace std;
 
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> tab(n, vector<int>(n));
	REP(i, n * 2) {
		string str;
		cin >> str;
		REP(j, n)
			tab[i % n][j] ^= str[j] == '1';
	}

	int cnt_1 = 0;
	REP(i, n) REP(j, n)
		cnt_1 += tab[i][j];

	vector<int> p(n);
	int any_1 = -1;
	REP(i, n) {
		char c;
		cin >> c;
		p[i] = c == '1';
		if(p[i]) any_1 = i;
	}

	debug(tab);

	if(any_1 == -1 && cnt_1 != 0) {
		cout << "-1\n";
		return 0;
	}

	vector<int> r(n), c(n);

	auto check = [&]() {
		REP(i, n) REP(j, n)
		if(tab[i][j] != ((r[i] & p[j]) ^ (c[j] & p[i])))
			c[j] ^= 1;
		bool ok = true;
		REP(i, n) REP(j, n)
			if(tab[i][j] != ((r[i] & p[j]) ^ (c[j] & p[i])))
				ok = false;
		return ok;
	};

	auto output = [&]() {
		vector<int> cols, rows;
		REP(i, n) if(c[i]) cols.emplace_back(i);
		REP(i, n) if(r[i]) rows.emplace_back(i);
		cout << size(cols) + size(rows) << "\n";
		for(int x : cols)
			cout << "col " << x << "\n";
		for(int x : rows)
			cout << "row " << x << "\n";
		exit(0);
	};


	// case 1 : c[any_1] = false
	REP(i, n) r[i] = tab[i][any_1];
	if(check()) output();
	// case 2 : c[any_1] = true
	c[any_1] = true;
	REP(i, n) r[i] = tab[i][any_1] ^ (c[any_1] & p[i]);
	if(check()) output();
	cout << "-1\n";
}