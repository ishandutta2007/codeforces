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

	string state;
	cin >> state;

	vector<vector<int>> q(n);
	REP(i, k) {
		int m;
		cin >> m;
		REP(j, m) {
			int x;
			cin >> x;
			q[x - 1].emplace_back(i);
		}
	}

	vector<vector<int>> comp(k);
	vector<int> val(k), rep(k), on(k), forced(k, -1);
	REP(i, k) comp[i] = {i}, rep[i] = i;

	int ans = 0;
	auto get_ans = [&](int i) {
		if(forced[i] == -1) return min(on[i], size(comp[i]) - on[i]);
		else if(forced[i] == 0) return size(comp[i]) - on[i];
		else return on[i];
	};

	auto force = [&](int i, int v) {
		int r = rep[i];
		if(forced[r] != -1) return;
		ans -= get_ans(r);
		forced[r] = val[i] ^ v;
		ans += get_ans(r);
	};

	auto merge = [&](int i, int j, int v) {
		if(rep[i] == rep[j]) return;

		int change = val[i] ^ val[j] ^ v;
		i = rep[i], j = rep[j];
		if(size(comp[i]) < size(comp[j]))
			swap(i, j);

		ans -= get_ans(i);
		ans -= get_ans(j);

		if(forced[j] != -1)
			forced[i] = forced[j] ^ change;

		for(int x : comp[j]) {
			comp[i].emplace_back(x);
			rep[x] = i;
			if(change) val[x] ^= 1;
			if(val[x]) on[i]++;
		}
		comp[j].clear();

		ans += get_ans(i);
	};

	REP(i, n) {
		if(size(q[i]) == 1)
			force(q[i][0], state[i] == '1');
		if(size(q[i]) == 2)
			merge(q[i][0], q[i][1], state[i] == '0');	

		cout << ans << "\n";
	}
}