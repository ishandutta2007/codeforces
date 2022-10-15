#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using std::cin;
using std::cout;
using std::cerr;
using std::min;
using std::max;
using std::abs;
using std::pair;
using std::swap;
using std::vector;
using std::set;
using std::map;
using std::string;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
	vector<string> _v;\
	string _cur, _loc;\
	std::stringstream _ss(#as);\
	while (getline(_ss, _cur, ',')) {\
		while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
			getline(_ss, _loc, ',');\
			_cur += _loc;\
		}\
		_v.pb(_cur);\
	}\
	err(_v.begin(), as);\
}
#else
#define dbg(as...) {}
#endif

struct init{
	init() {
		std::iostream::sync_with_stdio(0);
		cin.tie(0);
		cout << std::fixed << std::setprecision(10);
		cerr << std::fixed << std::setprecision(10);
		srand(123);
	}
	~init() {
		#ifdef LOCAL
		cerr << "Time elapsed: " << clock() * 1.0 / CLOCKS_PER_SEC << " s.\n";
		#endif
	}
};

template<typename T> 
void err(vector<string>::iterator it, T a) {
	cerr << *it << " = " << a << '\n';
} 
template<typename...Ts, typename T>
void err(vector<string>::iterator it, T a, Ts...as) {
	cerr << *it << " = " << a << ",";
	err(++it, as...);
} 

const int MAXN = 1e5 + 1;
int a[MAXN];

int main() {

	int n;
	int c = 0, ans = 0;
	cin>> n;
	for (int i = 0; i < n + n; ++i) {
		int x;
		cin >> x;
		if (a[x] == 0) {
			a[x] = 1;
			++c;
			ans = max(ans, c);
		}
		else if (a[x] == 1) {
			a[x] = 2;
			--c;
		}
	}

	cout << ans << '\n';



	return 0;
}