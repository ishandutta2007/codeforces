#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(228); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 1001, INF = 1e9 + 7;
int ans[MAXN];
vector<int> wo[MAXN];
int ret[20][MAXN];

int main() {

	int n;
	cin >> n;

	for (int step = 1, pw = 0; step < n; step *= 2, ++pw) {
		vector<int> q0, q1;
		for (int i = 0; i < n; i += step * 2) {
			for (int j = 0; j < step && i + j < n; ++j) {
				wo[i + j].pb(pw * 2 + 1);
				q0.pb(i + j);
			}
			for (int j = step; j < step + step && i + j < n; ++j) {
				q1.pb(i + j);
				wo[i + j].pb(pw * 2);
			}
		}
		if (!q0.empty()) {
			cout << q0.size() << '\n';
			for (int i : q0)
				cout << i+1 << ' ';
			cout << std::endl;
			for (int i = 0; i < n; ++i)
				cin >> ret[pw * 2][i];
		}
		if (!q1.empty()) {
			cout << q1.size() << '\n';
			for (int i : q1)
				cout << i+1 << ' ';
			cout << std::endl;
			for (int i = 0; i < n; ++i)
				cin >> ret[pw * 2 + 1][i];
		}
	}

	cout << "-1\n";
	for (int i = 0; i < n; ++i) {
		int mn = INF;
		for (int j : wo[i])
			mn = min(mn, ret[j][i]);
		cout << mn << ' ';
	}
	cout << std::endl;

    return 0;
}