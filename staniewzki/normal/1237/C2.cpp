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

	struct point {
		int x, y, z, id;
	};

	vector<point> pts(n);
	int q = 0;
	for(auto &p : pts) {
		cin >> p.x >> p.y >> p.z;
		p.id = ++q;
	}

	sort(pts.begin(), pts.end(), [&](point a, point b) {
		if(a.x != b.x) return a.x < b.x;
		if(a.y != b.y) return a.y < b.y;
		return a.z < b.z;
	});

	vector<point> r;
	for(int i = 0; i < n;) {
		int curr_x = pts[i].x;
		while(i < n && pts[i].x == curr_x) r.emplace_back(pts[i++]);
		sort(r.begin(), r.end(), [&](point a, point b) {
			if(a.y != b.y) return a.y < b.y;
			if(a.z != b.z) return a.z < b.z;
			return a.x < b.x;
		});

		vector<point> t;
		for(int j = 0; j < size(r);) {
			int curr_y = r[j].y;
			while(j < size(r) && r[j].y == curr_y) t.emplace_back(r[j++]);
			sort(t.begin(), t.end(), [&](point a, point b) {
				if(a.z != b.z) return a.z < b.z;
				if(a.x != b.x) return a.x < b.x;
				return a.y < b.y;
			});

			while(size(t) >= 2) {
				REP(k, 2) {
					cout << t.back().id << " ";
					t.pop_back();
				}
				cout << "\n";
			}
		}

		r = t;
	}
}