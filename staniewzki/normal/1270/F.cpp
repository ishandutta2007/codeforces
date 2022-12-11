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

	int n = size(str);
	int T = sqrt(n);
	LL ans = 0;

	vector<int> pref(n + 1);
	vector<int> cnt((T + 1) * n);
	REP(i, n) pref[i + 1] = pref[i] + str[i] - '0';
	FOR(k, 1, T) {
		auto x = [&](int i) { return pref[i] * k - i + n; };
		FOR(i, 0, n) ans += cnt[x(i)]++;
		FOR(i, 0, n) cnt[x(i)]--;
	}

	debug(T, ans);

	vector<int> z;
	int d = 0;
	REP(i, n) {
		if(str[i] == '1') {
			z.emplace_back(d);
			d = 0;
		}
		else d++;
	}
	z.emplace_back(d);

	debug(z);

	FOR(k, 1, n / T) {
		int len = k;
		REP(r, size(z)) {
			len += z[r];
			int l = r - k;
			if(l < 0) continue;
			FOR(x, 0, z[l]) {
				int lo = max(len - z[l] - z[r] + x - 1, T * k);
				int hi = len - z[l] + x;
				ans += max(0, hi / k - lo / k);
			}
			len -= z[l];
		}
	}

	cout << ans << "\n";
}