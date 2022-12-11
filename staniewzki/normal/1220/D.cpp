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
 
mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) {
	return uniform_int_distribution<int>(a, b)(_gen);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<LL> a(n);

	auto get_lg = [&](LL x) {
		int ret = 0;
		while(x % 2 == 0) {
			ret++;
			x /= 2;
		}
		return ret;
	};

	vector<int> cnt(100);
	int best = -1, id = -1;
	REP(i, n) {
		cin >> a[i];
		int lg = get_lg(a[i]);
		if(++cnt[lg] > best) {
			best = cnt[lg];
			id = lg;
		}
	}

	vector<LL> to_del;
	REP(i, n) {
		int lg = get_lg(a[i]);
		if(lg != id) to_del.emplace_back(a[i]);
	}

	cout << size(to_del) << "\n";
	for(LL x : to_del) cout << x << "\n";
}