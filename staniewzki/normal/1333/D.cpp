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

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) {
		char c;
		cin >> c;
		a[i] = (c == 'L');
	}

	vector<vector<int>> ops;
	int total = 0;
	while(true) {
		int last = -1;
		ops.emplace_back();
		FOR(j, 1, n - 1) {
			if(a[j] && !a[j - 1] && last != j - 1) {
				swap(a[j], a[j - 1]);
				last = j;
				ops.back().emplace_back(j);
				total++;
			}
		}
		if(!size(ops.back())) {
			ops.pop_back();
			break;
		}
	}

	debug(ops);

	if(size(ops) <= k && k <= total) {
		k -= size(ops);
		vector<vector<int>> ans;
		for(auto &v : ops) {
			ans.emplace_back(vector<int>{v[0]});
			FOR(i, 1, size(v) - 1) {
				if(k) {
					ans.emplace_back(vector<int>{v[i]});
					k--;
				}
				else ans.back().emplace_back(v[i]);
			}
		}

		for(auto y : ans) {
			cout << size(y) << " ";
			for(int x : y)
				cout << x << " ";
			cout << "\n";
		}
	}
	else cout << "-1\n";
}