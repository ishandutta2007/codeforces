#undef _GLIBCXX_DEBUG
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

	vector<int> x(n);
	REP(i, n) {
		char c;
		cin >> c;
		x[i] = c - '0';
	}

	vector<int> a(n);
	int good = 0;
	REP(i, n) {
		a[i] = x[i % k];
		if(good == 0 && a[i] < x[i]) {
			good = -1;	
			break;
		}
		else if(good == 0 && a[i] > x[i])
			good = 1;
	}

	debug(good);
	if(good != -1) {
		cout << n << "\n";
		for(int i : a) cout << i;
		cout << "\n";
		return 0;
	}

	vector<int> q(k);
	REP(i, k) q[i] = x[i];

	int c = 1;
	for(int i = k - 1; i >= 0; i--) {
		q[i] += c;
		c = 0;
		if(q[i] == 10) {
			c++;
			q[i] = 0;
		}

		if(!c) break;
	}

	if(c) {
		vector<int> t(k + 1, 0);
		t[0] = 1;
		q = t;
		n++;
	}

	cout << n << "\n";
	REP(i, n) cout << q[i % k];
	cout << "\n";
}