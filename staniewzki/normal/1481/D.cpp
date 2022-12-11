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
		vector<string> input(n);
		REP(i, n) cin >> input[i];

		bool found = false;
		REP(i, n) REP(j, n) {
			if(found) break;
			if(i != j && input[i][j] == input[j][i]) {
				found = true;
				cout << "YES\n";
				REP(k, m + 1) 
					cout << (k % 2 ? i : j) + 1 << " ";
				cout << "\n";
			}
		}

		if(found) continue;

		if(m % 2 == 1) {
			found = true;
			cout << "YES\n";
			REP(k, m + 1) 
				cout << (k % 2 ? 1 : 2) << " ";
			cout << "\n";
			continue;
		}

		if(n == 2) {
			cout << "NO\n";
			continue;
		}

		vector<int> path = {0, 1, 2};
		do {
			int x = path[0], y = path[1], z = path[2];
			if(input[x][y] == 'a' && input[y][z] == 'a')
				break;
		} while(next_permutation(path.begin(), path.end()));

		int x = path[0], y = path[1], z = path[2];

		if(m % 4 == 0) {
			vector<int> cycle = {y + 1, z + 1, y + 1, x + 1};
			cout << "YES\n";
			REP(k, m + 1)
				cout << cycle[k % size(cycle)] << " ";
			cout << "\n";
		}
		else if(m == 2) {
			cout << "YES\n";
			cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
		}
		else {
			cout << "YES\n";
			cout << x + 1 << " " << y + 1 << " " << z + 1 << " ";
			vector<int> cycle = {y + 1, z + 1, y + 1, x + 1};
			REP(k, m - 6 + 1)
				cout << cycle[k % size(cycle)] << " ";
			cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
		}
	}
}