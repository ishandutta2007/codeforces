#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

typedef ll NUM;

struct VEC{
	NUM x, y;
};

inline NUM cmp(NUM a, NUM b){
	return a - b;
}

inline NUM cmp(const VEC& a, const VEC& b){
    NUM at = cmp(a.x, b.x);
    return !at ? cmp(a.y, b.y) : at;
}


inline VEC operator -(const VEC& a, const VEC& b){
	return (VEC){a.x - b.x, a.y - b.y};
}

inline NUM operator *(const VEC& a, const VEC& b){
	return a.x * b.y - a.y * b.x;
}

inline NUM operator %(const VEC& a, const VEC& b){
	return a.x * b.x + a.y * b.y;
}

inline bool operator <(const VEC& a, const VEC& b){
	return cmp(a, b) < 0;
}

inline bool operator ==(const VEC& a, const VEC& b){
	return !cmp(a, b);
}


NUM cmp_side(const VEC& a, const VEC& b){
	return cmp(a.x * b.y, +a.y * b.x);
}

vector<VEC> convex_hull(vector<VEC> u){
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    if (u.size() < 3)
		return u;
    vector<VEC> c;
    for (size_t i = 0, o = 1, m = 1; ~i; i += o){
        while (c.size() > m){
            VEC a = c.back() - c[c.size() - 2];
            VEC b = c.back() - u[i];
            if (cmp_side(a, b) < 0)
				break;
            c.pop_back();
        }
        c.push_back(u[i]);
        if(i + 1 == u.size())
			m = c.size(), o = -1;
    }
    c.pop_back();
    return c;
}

const int N = 2E5 + 10;

pair<ll, pll> c[N], d[N];

inline NUM sqr(NUM x){
	return x * x;
}

inline NUM sqr(const VEC& a){
	return sqr(a.x) + sqr(a.y);
}

int kmp(int ls, pair<ll, pll> s[], ll lp, pair<ll, pll> p[]){
	static int fail[N] = {-1};
	for (int i, j = 1; j < lp; ++j){
		for (i = fail[j - 1]; i >= 0 && p[i + 1] != p[j]; i = fail[i]);
		fail[j] = p[i + 1] != p[j] ? i + 1 : -1;
	}
	for (int i = 0, j = 0; i < ls && j < lp; ++i)
		if (s[i] == p[j]){
			++j;
			if (j == lp)
				return true;
		}
		else if (j)
			j = fail[j - 1] + 1, --i;
	return false;
}

bool check(vector<VEC> &a, vector<VEC> &b){
	int m = a.size();

	a.push_back(a[0]);
	a.push_back(a[1]);
	b.push_back(b[0]);
	b.push_back(b[1]);

	for (int i = 1; i + 1 < a.size(); ++i){
		c[i - 1] = make_pair(sqr(a[i] - a[i - 1]),
					make_pair((a[i] - a[i - 1]) * (a[i + 1] - a[i]),
						(a[i] - a[i - 1]) % (a[i + 1] - a[i])));
	}
	for (int i = 1; i + 1 < b.size(); ++i){
		d[i - 1] = make_pair(sqr(b[i] - b[i - 1]),
					make_pair((b[i] - b[i - 1]) * (b[i + 1] - b[i]),
						(b[i] - b[i - 1]) % (b[i + 1] - b[i])));
	}
	copy(c, c + m, c + m);

	int ret = kmp(m * 2, c, m, d);
	a.pop_back();
	a.pop_back();
	b.pop_back();
	b.pop_back();
	return ret;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<VEC> a(n), b(m);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &a[i].x, &a[i].y);
	a = convex_hull(a);
	for (int i = 0; i < m; ++i)
		scanf("%lld%lld", &b[i].x, &b[i].y);
	b = convex_hull(b);

	puts(a.size() == b.size() && check(a, b) ? "YES" : "NO");
	return 0;
}