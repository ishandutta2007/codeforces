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

	vector<int> p(n), used(n);
	REP(i, n) {
		cin >> p[i];
		if(p[i] != 0)
			used[p[i] - 1] = true;
	}

	int l = 0, r = 0;
	REP(i, n) {
		if(!used[i]) {
			if((i + 1) % 2 == 0)
				l++;
			else
				r++;
		}
	}

	if(l + r == n) {
		if(n == 1) cout << "0\n";
		else cout << "1\n";
		return 0;
	}

	debug(l, r);

	int last = -1, len = 0, ans = 0;
	vector<int> L, R;
	REP(i, n) {
		if(p[i] == 0) len++;
		else {
			if(last == -1) {}
			else if(last % 2 == p[i] % 2) {
				if(max(p[i], last) % 2 == 0) L.emplace_back(len);
				else R.emplace_back(len);
				ans += 2;
			}
			else ans += 1;
			last = p[i], len = 0;
		}
	}

	sort(L.rbegin(), L.rend());
	sort(R.rbegin(), R.rend());
	auto CL = L, CR = R;
	auto cl = l, cr = r;
	auto cans = ans;

	int out = n;
	REP(i, 4) {
		L = CL, R = CR;
		l = cl, r = cr;
		ans = cans;

		if(i % 2 == 1) {
			int x = 0;
			while(p[x] == 0)
				x++;

			if(p[x] % 2 == 0) l -= x;
			else r -= x;
		}
		else
			ans++;

		if(i >= 2) {
			int x = 0;
			while(p[n - 1 - x] == 0)
				x++;

			if(p[n - 1 - x] % 2 == 0) l -= x;
			else r -= x;
		}
		else
			ans++;

		if(l < 0 || r < 0) continue;

		debug(i, l, r);
		debug(L, R);

		while(size(L) != 0 && L.back() <= l) {
			ans -= 2;
			l -= L.back();
			L.pop_back();
		}

		while(size(R) != 0 && R.back() <= r) {
			ans -= 2;
			r -= R.back();
			R.pop_back();
		}

		out = min(out, ans);
	}

	cout << out << "\n";
}