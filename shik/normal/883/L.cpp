// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
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

struct Car {
    int x;
    LL t;
    int id;
};

bool operator<( const Car &a, const Car &b ) {
    return tie(a.x,a.t,a.id)<tie(b.x,b.t,b.id);
}

int nh,nc,nr;
set<Car> avail;
MinHeap<pair<LL,Car>> work;

void pop_work( LL t ) {
    while ( !work.empty() && work.top().first<=t ) {
        avail.insert(work.top().second);
        work.pop();
    }
}

void main() {
    R(nh,nc,nr);
    REP(i,nc) {
        Car c;
        R(c.x);
        c.t=0;
        c.id=i+1;
        avail.insert(c);
    }
    REP(i,nr) {
        LL t;
        int a,b;
        R(t,a,b);
        pop_work(t);
        if ( avail.empty() ) pop_work(work.top().first);
        Car best{INT_MAX,0,0};
        auto key=[&]( const Car &c ) {
            return make_tuple(abs(c.x-a),c.t,c.id);
        };
        auto upd=[&]( const Car &c ) {
            if ( key(c)<key(best) ) best=c;
        };
        auto it=avail.lower_bound({a,0,0});
        if ( it!=avail.end() ) upd(*it);
        if ( it!=avail.begin() ) {
            it--;
            it=avail.lower_bound({it->x,0,0});
            assert(it!=avail.end());
            upd(*it);
        }
        LL wait=max(0LL,best.t-t)+abs(best.x-a);
        W(best.id,wait);
        avail.erase(best);
        best.x=b;
        best.t=t+wait+abs(b-a);
        work.push({best.t,best});
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}