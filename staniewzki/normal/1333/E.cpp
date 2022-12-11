#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
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
	if(n <= 2) {
		cout << "-1\n";
		return 0;
	}

	vector<vector<int>> a(n, vector<int>(n));
	int x = 0;
	for(int i = 0; i < n - 1; i++) {
		if((i + n) % 2) {
			for(int j = 0; j < n - 1; j++)
				a[j][i] = ++x;
		}
		else {
			for(int j = n - 2; j >= 0; j--)
				a[j][i] = ++x;
		}
	}

	a[0][n - 2] = n * n;
	a[0][n - 1] = x++;

	int p = 1, q = 0;
	REP(i, n - 1) {
		REP(j, 2) {
			if(i % 2)
				a[p++][n - 1] = x++;
			else 
				a[n - 1][q++] = x++;
		}
	}

	if(n == 3) {
		a = {
			{1, 9, 5},
			{2, 3, 6},
			{4, 7, 8}
		};
	}

	REP(i, n) {
		REP(j, n) cout << a[i][j] << " ";
		cout << "\n";
	}
}