#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;


const int MAXN = 16;
int n;
struct kal{
	char c;
	int r, b;
} a[MAXN];

inline int get() {
	int pot = n, hr = 0, hb = 0, fr = 0, fb = 0;
	for (int i = 0; i < n; ++i) {
		// dbg(a[i].c, a[i].r, a[i].b);
		int cr = a[i].r - hr;
		if (cr < 0) cr = 0;
		int cb = a[i].b - hb;
		if (cb < 0) cb = 0;
		int nr = cr - fr;
		if (nr < 0) nr = 0;
		int nb = cb - fb;
		if (nb < 0) nb = 0;

		int nn = nr;
		if (nr < nb) nn = nb;
		// dbg(hr, hb, fr, fb);
		// dbg(nr, nb, nn);
		
		pot += nn;
		fr -= cr - nn;
		fb -= cb - nn;
		
		if (a[i].c == 'R') ++hr;
		else ++hb;
	}
	return pot;
}

double random_double() {
	return rand() / (double) RAND_MAX;
}

int otzhig() {
	int ans = 1e9;
	double t0 = 1000;
	double temp = t0;

	for (int it = 0; it < 1000000 /*|| (double)clock() / CLOCKS_PER_SEC < 0.2*/; ++it) {
		if (it % 10000 == 0) dbg(temp);
		int cur = get();
		if (ans > cur)
			ans = cur;
		
		kal was[MAXN];
		memcpy(was, a, sizeof a);
		for (int i = 0; i < n * temp / t0; ++i) {
			if (it % 10000 == 0) dbg('+');
			swap(a[rand() % n], a[rand() % n]);
		}

		int pot = get();
		if (ans > pot)
			ans = pot;
		if (cur > pot)
			cur = pot;
		else {
			double go = exp(-(pot - cur) / temp);
			if (random_double() <= go)
				cur = pot;
			else
				memcpy(a, was, sizeof a);
		}

		temp *= 0.9999;
	}

	return ans;
}


int main() {

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].c >> a[i].r >> a[i].b;

	cout << otzhig() << '\n';

    return 0;
}