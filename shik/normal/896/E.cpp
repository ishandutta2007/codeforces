#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif

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

inline int read_char() {
    static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
    if (ptr == end_ptr) {
        int len = fread(buf, 1, sizeof(buf), stdin);
        if (len <= 0) return EOF;
        ptr = buf;
        end_ptr = buf + len;
    }
    return *ptr++;
}

inline int read_int() {
#undef getchar_unlocked
#define getchar_unlocked read_char
    int sg = +1, ch;
    do {
        ch = getchar_unlocked();
        if (ch == '-') sg = -1;
    } while (ch < '0' || ch > '9');
    int x = ch - '0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        x = x * 10 + ch - '0';
    }
    return sg * x;
}

void _R(int &x) { x=read_int(); }
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

namespace FastIO {

char bo[1 << 16], *po = bo;

void flush() {
    fwrite(bo, po - bo, 1, stdout);
    po = bo;
}

void write_char(char c) {
    *po++ = c;
    if (po == end(bo)) flush();
}

}

using FastIO::flush;
using FastIO::write_char;

void print_int(int x) {
    if (x == 0) {
        write_char('0');
        return;
    }
    char buf[16], *ed = buf;
    while (x != 0) {
        *ed++ = x % 10;
        x /= 10;
    }
    while (ed != buf) {
        write_char(*--ed + '0');
    }
}

const int N=1e5+10;
int n,m;
float __attribute__((aligned(64))) a[N];

void __attribute__((noinline)) solve1( int l, int r, int x ) {
    REP1(i,l,r) if ( a[i]>x ) a[i]-=x;
}

int __attribute__((noinline)) solve2( int l, int r, int x ) {
    int ans=0;
    REP1(i,l,r) ans+=(a[i]==x);
    return ans;
}

void main() {
    R(n,m);
    REP1(i,1,n) a[i]=read_int();
    REP(mi,m) {
        int op,l,r;
        R(op,l,r);
        float x=read_int();
        if ( op==1 ) {
            solve1(l,r,x);
            // REP1(i,l,r) a[i]=(a[i]>x ? a[i]-x : a[i]);
        } else {
            int ans=solve2(l,r,x);
            // int ans=0;
            // REP1(i,l,r) ans+=(a[i]==x);
            print_int(ans);
            write_char('\n');
            // W(ans);
        }
    }
    flush();
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}