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

struct event {
	LL t, s, i;
	event(LL t, LL s, LL i) : t(t), s(s), i(i) {}
};

bool operator<(event a, event b) {
	if(a.t != b.t) return a.t < b.t;
	if(a.s != b.s) return a.s > b.s;
	return a.i < b.i;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	vector<int> t(n);
	REP(i, n) cin >> t[i];
	set<event> S;
	REP(i, n) S.emplace(t[i], 1, i);
	vector<LL> ans(n);
	set<int> want, in_queue;
	LL queue_time = 0;
	while(!S.empty()) {
		auto it = S.begin();
		event e = *S.begin();
		S.erase(it);
		if(e.s == 1) want.emplace(e.i);
		else in_queue.erase(e.i);

		while(size(want)) {
			int id = *want.begin();
			if(in_queue.empty() || id < *in_queue.begin()) {
				want.erase(id);
				in_queue.emplace(id);
				LL l = max(e.t, queue_time) + p;
				queue_time = l;
				S.emplace(l, 0, id);
				ans[id] = l;
			}
			else break;
		}
	}

	REP(i, n) cout << ans[i] << " ";
	cout << "\n";
}