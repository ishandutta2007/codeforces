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

struct ans {
	int score;
	int l, r;
	ans() { score = 0, l = 0, r = 0; }
	void update(int s, int L, int R) {
		if(s > score) score = s, l = L, r = R;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string str;
	cin >> n >> str;

	vector<int> d(n);
	int cnt = 0;
	REP(i, n) {
		d[i] = (str[i] == '(' ? 1 : -1);
		if(d[i] == 1) cnt++;
	}

	if(cnt * 2 != n) {
		cout << "0\n1 1\n";
		return 0;
	}

	vector<int> s(n);
	int mn = 0;
	REP(i, n) {
		if(i) s[i] = s[i - 1];
		s[i] += d[i];
		mn = min(mn, s[i]);
	}

	vector<vector<int>> q(n, vector<int>(3));
	REP(i, n) {
		if(i) q[i] = q[i - 1];
		int r = s[i] - mn;
		if(r <= 2) q[i][r]++;
	}

	ans odp;
	// case 0 : nic nie robimy
	cnt = 0;
	REP(i, n)
		if(s[i] == mn) cnt++;
	odp.update(cnt, 0, 0);

	// case 1 : podnosimy
	auto go_up = [&]() {
		if(mn < 0) {
			int l = n, r = -1;
			REP(i, n) {
				if(s[i] == mn) {
					l = min(l, i);
					r = max(r, i);
				}
			}

			int p1 = q[l][1] + q[n - 1][1] - q[r][1];
			odp.update(p1, l, r + 1);
		}

		if(mn < -1) {
			int l = n, r = -1;
			REP(i, n) {
				if(s[i] <= mn + 1) {
					l = min(l, i);
					r = max(r, i);
				}
			}

			int p2 = q[l][2] + q[n - 1][2] - q[r][2] + q[n - 1][0];
			odp.update(p2, l, r + 1);
		}
	};
	go_up();

	// case 2 : opuszczamy
	auto go_down = [&]() {
		int l = -1, r = -1;
		REP(i, n) {
			if(s[i] >= 2 + mn) {
				if(l == -1) l = i;
				r = i;
				int p0 = q[n - 1][0] + q[r][2] - (l == 0 ? 0 : q[l - 1][2]);
				odp.update(p0, l, r + 1);
			}
			else l = -1, r = -1;
		}

		l = -1, r = -1;
		REP(i, n) {
			if(s[i] >= 1 + mn) {
				if(l == -1) l = i;
				r = i;
				int p1 = q[r][1] - (l == 0 ? 0 : q[l - 1][1]);
				odp.update(p1, l, r + 1);
			}
			else l = -1, r = -1;
		}
	};
	go_down();

	cout << odp.score << "\n" << odp.l + 1 << " " << odp.r + 1 << "\n";
}