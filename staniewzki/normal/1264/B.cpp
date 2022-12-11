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

	array<int, 4> in;
	REP(i, 4) cin >> in[i];

	REP(b, 4) {
		auto cnt = in;
		int q = -1;
		vector<int> path;
		auto move = [&](int d) { 
			path.emplace_back(q = d);
			return --cnt[q] < 0;
		};
		auto check = [&]() {
			bool r = true;
			REP(i, 4) if(cnt[i] != 0)
				r = false;
			return r;
		};

		move(b);	
		while(true) {
			debug(path, q, cnt);
			if(check()) break;
			if(q == 0) {
				if(move(1)) break;
			}
			else if(q == 1) {
				if(cnt[0]) {
					if(move(0)) break;
				}
				else {
					if(move(2)) break;
				}
			}
			else if(q == 2) {
				if(cnt[3]) {
					if(move(3)) break;
				}
				else {
					if(move(1)) break;
				}
			}
			else {
				if(move(2)) break;
			}
		}

		if(check()) {
			cout << "YES\n";
			for(int x : path) cout << x << " ";
			return 0;
		}
	}

	cout << "NO\n";
}