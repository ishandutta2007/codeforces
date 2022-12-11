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

	vector<int> a(n);
	REP(i, n) cin >> a[i];

	int ans = 0;
	for(int i = 0; i <= 25; i++) {
		auto get = [&](int x) {
			return x & ((1 << i) - 1);
		};

		vector<int> l, r;
		REP(j, n) {
			if(a[j] & (1 << i)) l.emplace_back(get(a[j]));
			else r.emplace_back(get(a[j]));
		}

		sort(l.begin(), l.end());
		sort(r.begin(), r.end());

		LL cnt = 0;

		auto cal = [&](vector<int> &v) {
			int pos = size(v) - 1;
			LL d = 0;
			REP(j, size(v)) {
				while(0 <= pos && v[j] + v[pos] >= (1 << i))
					pos--;

				int q = size(v) - 1 - pos;
				if(v[j] + v[j] >= (1 << i)) q--;
				d += q;
			}
			cnt += d / 2;
		};

		cal(l);
		cal(r);

		int pos = size(r) - 1;
		REP(j, size(l)) {
			while(0 <= pos && l[j] + r[pos] >= (1 << i))
				pos--;

			cnt += pos + 1;
		}

		if(cnt & 1) ans += (1 << i);
	}

	cout << ans << "\n";
}