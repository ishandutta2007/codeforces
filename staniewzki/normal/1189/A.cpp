#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

template<class T> int size(T && a) {
	return a.size();
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

mt19937_64 _gen(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(_gen); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string str;
	cin >> n >> str;

	array<int, 2> cnt = {0, 0};
	REP(i, n)
		cnt[str[i] - '0']++;

	if(cnt[0] != cnt[1]) {
		cout << "1\n";
		for(char c : str) cout << c;
		cout << "\n";
	}
	else {
		cout << "2\n";
		cout << str[0] << " ";
		FOR(i, 1, n - 1)
			cout << str[i];
		cout << "\n";
	}
}