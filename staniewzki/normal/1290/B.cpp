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

	string str;
	cin >> str;

	int A = 26, n = size(str);
	vector<vector<int>> pref(n + 1);
	vector<int> cur(A);

	pref[0] = cur;
	FOR(i, 1, n) {
		cur[str[i - 1] - 'a']++;
		pref[i] = cur;
	}

	int q;
	cin >> q;
	REP(i, q) {
		int l, r;
		cin >> l >> r;
		int dif = 0;
		REP(j, A) {
			if(pref[r][j] - pref[l - 1][j])
				dif++;
		}

		if(r - l + 1 == 1 || dif > 2)
			cout << "Yes\n";
		else if(dif == 2) {
			if(str[l - 1] != str[r - 1])
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else 
			cout << "No\n";
	}
}