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

const int N=2e5+10;


struct P {
    char c;
    int l;
};

char s1[N],s2[N];

deque<P> build( char *s ) {
    deque<P> v;
    int n=strlen(s);
    for ( int i=0,j; i<n; i=j ) {
        for ( j=i; s[i]==s[j]; j++ );
        v.PB({s[i],j-i});
    }
    return v;
}

void merge( deque<P> &a, deque<P> &b ) {
    if ( a.empty() ) return;
    if ( b.empty() ) {
        b=a;
        return;
    }
    if ( a.back().c==b.front().c ) {
        b.front().l+=a.back().l;
        a.pop_back();
    }
    while ( !a.empty() ) {
        b.push_front(a.back());
        a.pop_back();
    }
}

pair<string,string> go( string z1, string z2, int l1, int l2 ) {
    string nz1=z2.substr(0,l2)+z1.substr(l1);
    string nz2=z1.substr(0,l1)+z2.substr(l2);
    return {nz1,nz2};
}

deque<P> q1,q2;
vector<PII> sol;
void go( int k1, int k2 ) {
    assert(k1<=SZ(q1));
    assert(k2<=SZ(q2));
    deque<P> t1,t2;
    while ( k1-- ) {
        t1.push_back(q1.front());
        q1.pop_front();
    }
    while ( k2-- ) {
        t2.push_back(q2.front());
        q2.pop_front();
    }
    int l1=0,l2=0;
    for ( auto i:t1 ) l1+=i.l;
    for ( auto i:t2 ) l2+=i.l;
    sol.PB({l1,l2});
    swap(t1,t2);
    merge(t1,q1);
    merge(t2,q2);
#ifdef SHIK
    static string z1,z2;
    if ( z1.empty() && z2.empty() ) z1=s1,z2=s2;
    auto [nz1,nz2]=go(z1,z2,l1,l2);
    z1=nz1;
    z2=nz2;
    dump(z1,z2);
#endif
}

string reduce( const string &s ) {
    string t;
    for ( auto c:s ) if ( t.empty() || c!=t.back() ) t.push_back(c);
    return t;
}
int slow( string z1, string z2 ) {
    z1=reduce(z1);
    z2=reduce(z2);
    static map<pair<string,string>,int> dp;
    if ( SZ(z1)==1 && SZ(z2)==1 ) return 0;
    auto k=make_pair(z1,z2);
    if ( dp.count(k) ) return dp[k];
    int mi=INT_MAX;
    REP(i,SZ(z1)+1) REP(j,SZ(z2)+1) {
        auto [nz1,nz2]=go(z1,z2,i,j);
        nz1=reduce(nz1);
        nz2=reduce(nz2);
        if ( SZ(nz1)+SZ(nz2)<SZ(z1)+SZ(z2) || max(SZ(nz1),SZ(nz2))<max(SZ(z1),SZ(z2)) ) {
            if ( chkmin(mi,slow(nz1,nz2)+1) ) {
                // dump(z1,z2,i,j,mi,nz1,nz2);
            }
        }
    }
    // dump(z1,z2,mi);
    return dp[k]=mi;
}

void main() {
    R(s1,s2);
    q1=build(s1);
    q2=build(s2);
    while ( q1.front().c==q2.front().c ) {
        if ( max(SZ(q1),SZ(q2))>=3 && min(SZ(q1),SZ(q2))>=2 ) {
            if ( SZ(q1)>SZ(q2) ) go(2,1);
            else go(1,2);
        } else {
            if ( SZ(q1)>SZ(q2) ) go(SZ(q1)>=5 ? 3 : 1,0);
            else go(0,SZ(q2)>=5 ? 3 : 1);
        }
    }
    assert(!q1.empty() && !q2.empty());
    assert(q1.front().c!=q2.front().c);
    while ( SZ(q1)>1 || SZ(q2)>1 ) {
        int k1=1,k2=1;
        if ( SZ(q1)>=SZ(q2)+3 ) k1=3;
        else if ( SZ(q2)>=SZ(q1)+3 ) k2=3;
        go(k1,k2);
    }
    W(SZ(sol));
    for ( auto i:sol ) W(i.first,i.second);
#ifdef SHIK
    int slow_ans=slow(s1,s2);
    dump(slow_ans);
    assert(slow_ans==SZ(sol));
#endif
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}