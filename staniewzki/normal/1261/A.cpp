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

	int t;
	cin >> t;
	REP(it, t) {
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;

		vector<PII> ops;
		auto reverse = [&](int l, int r) {
			int len = r - l + 1;
			REP(i, len / 2) swap(str[l + i], str[r - i]);
			ops.emplace_back(l + 1, r + 1);
		};

		auto find = [&](int i, char c) {
			FOR(j, i, n - 1) if(str[j] == c) return j;
		};

		k--;
		int q = n - 2 * k;
		int pos = 0;
		REP(i, q / 2) {
			int f = find(pos, '(');
			reverse(pos++, f);
		}

		REP(i, q / 2) {
			int f = find(pos, ')');
			reverse(pos++, f);
		}

		REP(i, (n - q) / 2) {
			int f = find(pos, '(');
			reverse(pos++, f);
			f = find(pos, ')');
			reverse(pos++, f);
		}

		cout << size(ops) << "\n";
		REP(i, size(ops)) cout << ops[i].ST << " " << ops[i].ND << "\n";
		debug(str);
	}
}