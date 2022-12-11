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

	int cap = 2e5 + 1;
	vector<int> prime(cap, -1);
	for(int i = 2; i < cap; i++)
		if(prime[i] == -1)
			for(int j = i; j < cap; j += i)
				prime[j] = i;

	vector<vector<int>> cnt(cap);

	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		
		while(a != 1) {
			int p = prime[a], f = 0;
			while(a % p == 0)
				f++, a /= p;
			cnt[p].emplace_back(f);
		}
	}

	LL ans = 1;
	for(int i = 2; i < cap; i++) {
		if(size(cnt[i]) >= n - 1) {
			sort(cnt[i].rbegin(), cnt[i].rend());
			REP(j, cnt[i][n - 2]) 
				ans *= i;
		}
	}

	cout << ans << "\n";
}