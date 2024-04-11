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
template<class T> int sz(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> val(n + 1, -1);
	vector<int> q;
	REP(i, min(k, n - k + 1)) {
		cout << "? ";
		int l = k;
		FOR(j, 1, n) {
			if(l && val[j] == -1) {
				l--;
				cout << j << " ";
			}
		}
		cout << endl;

		int pos, v;
		cin >> pos >> v;
		val[pos] = v;
		q.emplace_back(pos);
	}

	if(size(q) == k) {
		cout << "? ";
		vector<PII> x;
		FOR(i, 1, n) {
			if(val[i] != -1) {
				cout << i << " ";
				x.emplace_back(val[i], i);
			}
		}
		cout << endl;
		int pos, v;
		cin >> pos >> v;
		sort(x.begin(), x.end());

		REP(i, k) {
			if(x[i].ST == v) {
				cout << "! " << i + 1 << endl;
				return 0;
			}
		}
	}
	else {
		vector<int> r;
		FOR(i, 1, n) if(val[i] == -1)
			r.emplace_back(i);

		debug(r);

		int a = q[size(q) - 2], b = q[size(q) - 1];
		int lower = 0;
		REP(i, size(r)) {
			cout << "? " << a << " " << b << " ";
			REP(j, size(r)) if(i != j)
				cout << r[j] << " ";
			cout << endl;

			int pos, v;
			cin >> pos >> v;
			if(val[a] < val[b] && pos == b) lower++;
			if(val[a] > val[b] && pos != b) lower++;
		}

		cout << "! " << lower + 1 << endl;
	}

}