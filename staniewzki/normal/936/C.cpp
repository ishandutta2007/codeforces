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

vector<int> ans;
void shift(string &str, int x) {
	ans.emplace_back(x);
	string a, b;
	int n = size(str);
	REP(i, n - x) a += str[i];
	FOR(i, n - x, n - 1) b += str[i];
	reverse(b.begin(), b.end());
	str = b + a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	auto count_letters = [&](string &str) {
		array<int, 30> ret = {};
		for(char c : str) ret[c - 'a']++;
		return ret;
	};

	if(count_letters(s) != count_letters(t)) {
		cout << "-1\n";
		return 0;
	}

	REP(i, n) {
		char c = t[i];
		int p = -1;
		REP(j, n) {
			if(s[j] == c) {
				p = j;
				break;
			}
		}
	
		shift(s, n - 1 - p);
		shift(s, 1);
		shift(s, n);
	}

	debug(s, t);

	cout << size(ans) << "\n";
	for(int x : ans) cout << x << " ";
	cout << "\n";
}