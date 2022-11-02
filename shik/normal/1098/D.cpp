// {{{ by shik
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

const int C=1e9+1;

// {{{ BIT
template<class T>
struct BIT {
	int n;
	vector<T> dat;
	void init(int _n) {
		n = _n;
		dat.clear();
		dat.resize(n + 1);
	}
	template<bool ask_range>
	void init(int _n, T a[]) {
		init(_n);
		for (int i = 1; i <= n; i++) {
			dat[i] += ask_range ? a[i] : a[i] - a[i - 1];
			int j = i + (i & -i);
			if (j <= n) dat[j] += dat[i];
		}
	}
	void add(int x, T v) {
		for (int i = x; i <= n; i += i & -i) dat[i] += v;
	}
	T ask(int x) {
		T s = T();
		for (int i = x; i; i -= i & -i) s += dat[i];
		return s;
	}
	// cannot add/ask a range simultaneously!
	void add(int l, int r, T v) {
		add(l, v);
		if (r + 1 <= n) add(r + 1, -v);
	}
	T ask(int l, int r) {
		return ask(r) - ask(l - 1);
	}
};
// }}}

template<class T>
struct SortedSet : vector<T> {
    void add(const T& x) { this->push_back(x); }
    void build() {
        sort(this->begin(), this->end());
        this->resize(unique(this->begin(), this->end()) - this->begin());
    }
    bool has(const T& x) {
        return binary_search(this->begin(), this->end(), x);
    }
    auto lower_bound(const T& x) {
        return std::lower_bound(this->begin(), this->end(), x);
    }
    int rank(const T& x) {
        return this->lower_bound(x) - this->begin();
    }
};

const int N=5e5+10;

struct Q {
    char op;
    int x;
} q[N];

void add( int &a, int b ) {
    a+=b;
    if ( a>C ) a=C;
}

BIT<LL> b;
SortedSet<int> r;

void main() {
    int n;
    R(n);
    REP(i,n) R(q[i].op,q[i].x);
    b.init(n);
    REP(i,n) r.add(q[i].x);
    r.build();

    multiset<int> st;
    REP(i,n) {
        int x=q[i].x;
        int id=r.rank(x)+1;
        if ( q[i].op=='+' ) {
            st.insert(x);
            b.add(id,x);
        } else {
            st.erase(st.find(x));
            b.add(id,-x);
        }
        if ( st.empty() ) {
            W(0);
            continue;
        }
        int cnt=0,t=*st.begin();
        while ( 1 ) {
            int tid=[&] {
                int p=r.rank(2*t);
                if ( p==SZ(r) || r[p]>2*t ) p--;
                return p+1;
            }();
            int nt=min((LL)C,b.ask(tid));
            if ( t==nt ) {
                auto it=st.lower_bound(2*t);
                if ( it==st.end() ) break;
                cnt++;
                add(t,*it);
            } else {
                t=nt;
            }
        }
        W(SZ(st)-1-cnt);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}