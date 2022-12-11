#include<bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		bool found = false;
		REP(i, n) {
			cin >> a[i];
			if(a[i] < k) a[i] = -1;
			else if(a[i] == k) a[i] = 1, found = true;
			else a[i] = 1;
		}

		if(!found) {
			cout << "No\n";
			continue;
		}

		found = (n == 1);
		vector<int> pref(n + 1);
		int s = 1e9;
		FOR(i, 1, n) {
			pref[i] = pref[i - 1] + a[i - 1];
			if(pref[i] - s > 0) found = true;
			s = min(s, pref[i - 1]);
		}

		cout << (found ? "Yes\n" : "No\n");
	}
}