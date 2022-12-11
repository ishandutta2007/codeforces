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

	vector<int> ans;

	int l = 0, r = size(str) - 1;
	while(l < r) {
		while(l < r && str[l] == ')') l++;
		while(l < r && str[r] == '(') r--;
		if(l < r) {
			ans.emplace_back(l++);
			ans.emplace_back(r--);
		}
	}

	sort(ans.begin(), ans.end());
	if(size(ans) == 0) {
		cout << "0\n";
		return 0;
	}

	cout << 1 << "\n" << size(ans) << "\n";
	REP(i, size(ans)) cout << ans[i] + 1 << " ";
	cout << "\n";
}