#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)
#define fork(i, k, n) for(int i = int(k); i <= int(n); ++i)
#define forft(i, from, to) for(int i = int(from); i < int(to); ++i)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define mnp(a, b) make_pair((a) < (b) ? (a) : (b), (a) < (b) ? (b) : (a))
#define sz(d) int(d.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define msn(a, v, n) memset(a, v, n * sizeof(a[0]))
#define mcn(dst, src, n) memcpy(dst, src, n * sizeof(src[0]))
#define X first
#define Y second
#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))

template<typename T> T sqr(const T &x) {
	return x * x;
}

template<typename T> T my_abs(const T &x) {
	return x < 0 ? -x : x;
}

typedef long long li;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<li,li> pli;
typedef pair<ld,ld> pd;

const int INF = (int)1e9;
const li LINF = (li)6e18;
const li INF64 = LINF;
const li INFLL = LINF;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

int gid = 0;

struct node {
	node* to[5];
	int cnt;
	int id;
	
	node() {
		cnt = 0;
		ms(to, 0);
		id = gid++;
	}
};

const int N = 52 * 100 * 1000 + 10;

int used[N];

int T = 0;

node* root = new node();

void add_word(node* cur, const string& s, int i = 0) {
	if (i == sz(s)) {
		cur->cnt++;
	} else {
		int c = s[i] - 'a';
		if (!cur->to[c]) {
			cur->to[c] = new node();
		}
		add_word(cur->to[c], s, i + 1);
	}
}

int n, m;

char buf[100];

int calc(node* cur, const string& s, int i = 0) {
	if (!cur) {
		return 0;
	}
	if (i == sz(s)) {
		if (used[cur->id] != T) {
			used[cur->id] = T;
			return cur->cnt;			
		} else {
			return 0;
		}
	} else {
		if (s[i] != '?') {
			int c = s[i] - 'a';
			return calc(cur->to[c], s, i + 1);
		} else {
			int res = calc(cur, s, i + 1);
			forn(c, 5) {
				res += calc(cur->to[c], s, i + 1);
			}
			return res;
		}
	}
}

bool read() {
	scanf("%d%d\n", &n, &m);
	forn(i, n) {
		scanf("%s\n", buf);
		//cerr << string(buf) << endl;
		add_word(root, string(buf));
	}
	return true;
}

void solve() {
	forn(i, m) {
		scanf("%s\n", buf);
		T++;
		int ans = calc(root, string(buf));
		printf("%d\n", ans);
	}
}

//#define FILES

#define TASK "taskname"

int main() {

#ifdef SU2_PROJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#ifdef FILES	
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
#endif
	
	srand((unsigned int)time(NULL));

	cout << setprecision(15) << fixed;

	read();
	solve();
	
#ifdef SU2_PROJ
	cerr << "time: " << clock() << " ms" << endl;
#endif

	return 0;
}