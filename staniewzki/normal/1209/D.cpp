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

mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) {
	return uniform_int_distribution<int>(a, b)(_gen);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<PII> f(k);
	REP(i, k) {
		cin >> f[i].ST >> f[i].ND;
		f[i].ST--, f[i].ND--;
		if(f[i].ST > f[i].ND)
			swap(f[i].ST, f[i].ND);
	}

	sort(f.begin(), f.end());
	auto it = unique(f.begin(), f.end());
	f.erase(it, f.end());

	int ans = k;
	k = size(f);
	vector<vector<int>> p(n);
	vector<int> deg(n);
	vector<bool> used(k);

	REP(i, k) {
		auto add_edge = [&](int v) {
			deg[v]++;
			p[v].emplace_back(i);
		};

		add_edge(f[i].ST);
		add_edge(f[i].ND);
	}

	vector<int> S;
	vector<bool> fla(n);
	REP(i, n) {
		if(deg[i] == 1)
			S.emplace_back(p[i][0]);
	}

	int last_not_used = 0;
	while(last_not_used != k) {
		int v = -1;
		while(!S.empty() && (v == -1 || used[v])) {
			v = S.back();
			S.pop_back();
		}

		if(v == -1 || used[v]) {
			while((v == -1 || used[v]) && last_not_used != k)
				v = last_not_used++;	
		}

		if(last_not_used == n) break;
		used[v] = true;

		if(!fla[f[v].ST] || !fla[f[v].ND]) ans--;
		for(int u : {f[v].ST, f[v].ND}) {
			if(fla[u]) continue;
			fla[u] = true;
			for(int x : p[u])
				S.emplace_back(x);
		}
	}

	cout << ans << "\n";
}