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

LL query(int t, int i, int j, int k) {
	cout << t << " " << i << " " << j << " " << k << endl;
	LL resp;
	cin >> resp;
	return resp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a = 1, b = 2;
	FOR(i, 3, n) if(query(2, a, b, i) == -1) b = i;
	debug(a, b);

	vector<LL> area(n + 1);
	FOR(i, 2, n) if(i != b)
		area[i] = query(1, a, b, i);

	vector<int> ord(n);
	REP(i, n) ord[i] = i + 1;
	sort(ord.begin(), ord.end(), 
	[&](int i, int j) { return area[i] < area[j]; });
	debug(ord);

	int f = ord.back();
	vector<int> hull = {a, b};
	FOR(i, 2, n - 2) {
		int x = ord[i];
		if(query(2, b, f, x) == -1)
			hull.emplace_back(x);
	}
	vector<bool> used(n + 1);
	for(int x : hull) used[x] = true;
	for(int i = n - 1; i >= 0; i--) {
		int x = ord[i];
		if(!used[x]) hull.emplace_back(x);
	}

	cout << "0 ";
	for(int x : hull) cout << x << " ";
	cout << "\n";
}