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

/*
 * Opis: radius[p][i] = $rad$ = najwikszy promie palindromu
 *   parzystoci p o rodku i. $L=i-rad+!p, \; R=i+rad$ to palindrom.
 *   Dla [abaababaab] daje [003000020], [0100141000].
 * Czas: O(n)
 */

array<vector<int>, 2> manacher(string &in) {
	int n = size(in);
	array<vector<int>, 2> radius = {{vector<int>(n - 1), vector<int>(n)}};
	REP(parity, 2) {
		int z = parity ^ 1, L = 0, R = 0;
		REP(i, n - z) {
			int &rad = radius[parity][i];
			if(i <= R - z)
				rad = min(R - i, radius[parity][L + (R - i - z)]);
			int l = i - rad + z, r = i + rad;
			while(0 <= l - 1 && r + 1 < n && in[l - 1] == in[r + 1])
				++rad, ++r, --l;
			if(r > R)
				L = l, R = r;
		}
	}
	return radius;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(it, t) {
		string str;
		cin >> str;

		int len = 0, n = size(str);
		while((len + 1) * 2 <= n && str[len] == str[n - 1 - len])
			len++;

		auto pal = manacher(str);

		PII ans = {0, -1};
		REP(i, n) {
			// nieparzysty
			if(i - pal[1][i] <= len || n - len - 1 <= i + pal[1][i]) {
				int x = min(2 * i + 1, (n - i) * 2 - 1);
				ans = max(ans, {x, i});
			}

			// parzysty
			if(i == n - 1) break;
			if(i - pal[0][i] <= len - 1 || n - len - 1 <= i + pal[0][i]) {
				int x = min(2 * i + 2, (n - i) * 2 - 2);
				ans = max(ans, {x, i});
			}
		}

		REP(i, len) cout << str[i];
		int q = ans.ST - 2 * len;
		if(q % 2 == 1) {
			FOR(i, -(q / 2), q / 2)
				cout << str[i + ans.ND];
		}
		else {
			FOR(i, - (q / 2 - 1), q / 2)
				cout << str[i + ans.ND];
		}
		for(int i = len - 1; i >= 0; i--) cout << str[i];
		cout << "\n";
	}
}