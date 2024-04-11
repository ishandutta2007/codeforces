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

const int N=1e5+10;
const LL K=1e18+10;
const char *f0="What are you doing at the end of the world? Are you busy? Will you save us?";
const char *f1="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
const char *t1="What are you doing while sending \"";
const char *t3="\"? Are you busy? Will you send \"";
const char *t5="\"?";
LL fl[N];
void main() {
    fl[0]=strlen(f0);
    REP1(i,1,N-1) fl[i]=min(K,(int)strlen(f1)+2*fl[i-1]);
    int t;
    R(t);
    while ( t-- ) {
        int n;
        LL k;
        R(n,k); k--;
        if ( k>=fl[n] ) {
            putchar('.');
        } else {
            while ( n>0 ) {
                LL l1=strlen(t1);
                LL l2=fl[n-1];
                LL l3=strlen(t3);
                LL l4=fl[n-1];
                LL l5=strlen(t5);

                if ( k<l1 ) {
                    putchar(t1[k]);
                    break;
                } else {
                    k-=l1;
                }

                if ( k<l2 ) {
                    n--;
                    continue;
                } else {
                    k-=l2;
                }
                
                if ( k<l3 ) {
                    putchar(t3[k]);
                    break;
                } else {
                    k-=l3;
                }

                if ( k<l4 ) {
                    n--;
                    continue;
                } else {
                    k-=l4;
                }

                if ( k<l5 ) {
                    putchar(t5[k]);
                    break;
                } else {
                    assert(0);
                }
            }
            if ( n==0 ) {
                assert(k<(LL)strlen(f0));
                putchar(f0[k]);
            }
        }
    }
    W("");
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}