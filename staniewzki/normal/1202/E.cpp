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

vector<int> sort_shifts(string &str) {
	int n = size(str), alf = 256;
	vector<int> p(n), c(n), cnt(max(alf, n));
	REP(i, n) cnt[str[i]]++;
	FOR(i, 1, alf - 1) cnt[i] += cnt[i - 1];
	REP(i, n) p[--cnt[str[i]]] = i;
	FOR(i, 1, n - 1) {
		c[p[i]] = c[p[i - 1]];
		if(str[p[i - 1]] != str[p[i]]) c[p[i]]++;
	}
	vector<int> pn(n), cn(n);
	for(int k = 0; (1 << k) < n; ++k) {
		auto mod = [&](int a, int b) { return (a + b + n) % n; };
		REP(i, n) pn[i] = mod(p[i], - (1 << k));
		fill(cnt.begin(), cnt.end(), 0);
		REP(i, n) cnt[c[i]]++;
		FOR(i, 1, size(cnt) - 1) cnt[i] += cnt[i - 1];
		for(int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		FOR(i, 1, n - 1) {
			cn[p[i]] = cn[p[i - 1]];
			PII prev = {c[p[i - 1]], c[mod(p[i - 1], 1 << k)]};
			PII curr = {c[p[i]], c[mod(p[i], 1 << k)]};
			if(prev != curr) cn[p[i]]++;
		}
		swap(cn, c);
	}
	return p;
}

vector<int> suffix_array(string str) {
	str += "$";
	auto ret = sort_shifts(str);
	ret.erase(ret.begin());
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	int n = size(str), q;
	cin >> q;

	vector<string> t(q);
	REP(i, q) cin >> t[i];

	auto get_beg = [&]() {
		auto sa = suffix_array(str);

		auto compare = [&](int i, int j, bool ret_equal) {
			REP(len, size(t[j])) {
				if(i + len == n) return false;
				if(str[i + len] > t[j][len]) return true;
				if(str[i + len] < t[j][len]) return false;
			}
			return ret_equal;
		};

		auto binsearch = [&](int i, bool ret_equal) {
			int l = 0, r = n;
			while(l < r) {
				int m = (l + r) / 2;
				if(compare(sa[m], i, ret_equal))
					r = m;
				else
					l = m + 1;
			}
			return l;
		};

		vector<int> pref(n + 1);
		REP(i, q) {
			pref[binsearch(i, true)]++;
			pref[binsearch(i, false)]--;
		}
		FOR(i, 1, n) pref[i] += pref[i - 1];

		vector<int> ret(n);
		REP(i, n) ret[sa[i]] = pref[i];
		return ret;
	};

	auto beg1 = get_beg();
	reverse(str.begin(), str.end());
	REP(i, q) reverse(t[i].begin(), t[i].end());
	auto beg2 = get_beg();

	LL ans = 0;
	FOR(i, 1, n - 1) ans += (LL) beg1[i] * beg2[n - i];	
	cout << ans << "\n";
}