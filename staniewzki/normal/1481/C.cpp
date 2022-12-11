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
		int n, m;
		cin >> n >> m;

		vector<int> a(n), b(n), c(m);
		REP(i, n) cin >> a[i];
		REP(i, n) cin >> b[i];
		REP(i, m) cin >> c[i];

		int last = -1;
		REP(i, n) {
			if(b[i] == c.back()) {
				last = i;
				break;
			}
		}

		if(last == -1) {
			cout << "NO\n";
			continue;
		}

		vector<vector<int>> needed(n + 1);
		REP(i, n)
			if(a[i] != b[i]) 
				needed[b[i]].emplace_back(i);

		vector<int> ile(n + 1);
		REP(i, m)
			ile[c[i]]++;

		if(ile[c.back()] == size(needed[c.back()]))
			last = needed[c.back()][0];

		vector<int> output(m);
		REP(i, m) {
			if(size(needed[c[i]]) == 0)
				output[i] = last;
			else {
				output[i] = needed[c[i]].back();
				needed[c[i]].pop_back();
			}
		}

		bool ret = true;
		REP(i, n + 1)
			if(size(needed[i]))
				ret = false;

		if(ret) {
			cout << "YES\n";
			for(int i : output)
				cout << i + 1 << " ";
			cout << "\n";
		}
		else cout << "NO\n";
	}
}