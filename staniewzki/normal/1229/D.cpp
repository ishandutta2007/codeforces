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

	vector<int> per(k);
	REP(i, k) per[i] = i;
	map<vector<int>, int> per_to_id;
	map<int, vector<int>> id_to_per;
	int x = 0;
	do {
		per_to_id[per] = x;
		id_to_per[x++] = per;
	} while(next_permutation(per.begin(), per.end()));

	vector<vector<int>> add(x, vector<int>(x));
	REP(i, x) {
		vector<int> A = id_to_per[i];
		REP(j, x) {
			vector<int> B = id_to_per[j];
			vector<int> C = B;
			REP(q, k) C[q] = A[B[q]];
			add[i][j] = per_to_id[C];
		}
	}

	vector<int> pos(x, -1);
	LL ans = 0;
	REP(r, n) {
		vector<int> A(k);
		REP(i, k) {
			cin >> A[i];
			A[i]--;
		}

		int id = per_to_id[A];
		pos[id] = r;
		debug(pos);

		vector<PII> occ(x);	
		REP(i, x) occ[i] = {pos[i], i};
		sort(occ.rbegin(), occ.rend());
		vector<bool> able(x);
		vector<int> gen;

		for(auto &p : occ) {
			int l = p.ST;
			int t = p.ND;
			if(l == -1) break;
			if(able[t]) continue;
			gen.emplace_back(t);

			auto update = [&](int v) {
				debug(r, v, l);
				able[v] = true;
				ans += l + 1;
			};
			
			update(t);
			vector<int> Q = {t};
			while(!Q.empty()) {
				int v = Q.back();
				Q.pop_back();
				for(int i : gen) if(!able[add[v][i]]) {
					update(add[v][i]);
					Q.emplace_back(add[v][i]);
				}
			}
		}

		debug(able);
	}

	cout << ans << "\n";
}