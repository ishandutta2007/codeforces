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
    vector<string> _v;\
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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

int num(string s) {
	string t[7] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};
	for (int i = 0; i < 7; ++i)
		if (s == t[i])
			return i;
}

string str(int x) {
	string t[7] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};
	return t[x];
}

bool ok(int w) {
	return 0 <= w && w <= 6;
}

int main() {

	int cnt[7] = {0};
	for (int i = 1; i <= 6; ++i)
		cin >> cnt[i];

	int n;
	cin >> n;
	vector<int> nums[7][7];
	bool inq[7][7];
	for (int i = 0; i < 7; ++i) for (int j = 0; j < 7; ++j) inq[i][j] = false;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		string ft;
		bool zpt = false;
		uint j = 0;
		for (; j < s.size(); ++j) {
			if (s[j] == ',') {
				++j;
				zpt = true;
				break;
			}
			ft += s[j];
		}
		string sd;
		if (zpt) {
			for (; j < s.size(); ++j)
				sd += s[j];
		}
		nums[num(ft)][num(sd)].pb(i);
	}

	std::queue<pii> q;
	for (int i = 0; i <= 6; ++i) {
		inq[i][0] = true;
		q.push({i, 0});
	}

	vector<int> ans(n);
	int ni = 0, nj = 1;
	while (!q.empty()) {
		pii v = q.front();
		q.pop();
		int x = v.ff, y = v.ss;
		dbg(x, y);
		for (int i : nums[x][y]) {
			dbg(i);
			if (cnt[x] > 0) {
				--cnt[x];
				ans[i] = x;
				if (cnt[x] == 0) {
					if (ok(x - 1) && !inq[x - 1][x]) {
						inq[x - 1][x] = true;
						q.push({x - 1, x});
					}
					if (ok(x + 1) && !inq[x][x + 1]) {
						inq[x][x + 1] = true;
						q.push({x, x + 1});
					}
				}
			} else if (cnt[y] > 0) {
				--cnt[y];
				ans[i] = y;
				if (cnt[y] == 0) {
					if (ok(y - 1) && !inq[y - 1][y]) {
						inq[y - 1][y] = true;
						q.push({y - 1, y});
					}
					if (ok(y + 1) && !inq[y][y + 1]) {
						inq[y][y + 1] = true;
						q.push({y, y + 1});
					}
				}
			} else {
				cout << "NO\n";
				return 0;
			}
			dbg(ans[i]);
		}
		if (q.empty()) {
			for (; nj < 7; ++nj) {
				for (; ni < 7; ++ni)
					if (!inq[ni][nj])
					{
						q.push({ni, nj});
						inq[ni][nj] = true;
						goto out;
					}
				ni = 1;
			}

			out:;
		}
	}
	cout << "YES\n";
	for (int i : ans)
		cout << str(i) << '\n';

    return 0;
}