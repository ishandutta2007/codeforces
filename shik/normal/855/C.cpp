// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {
    _R(head);
    R(tail...);
}

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f\n", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) {
    for (auto i = x.begin(); i != x.end(); _W(*i++)) {
        if (i != x.cbegin()) putchar(' ');
    }
}
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) {
    _W(head);
    putchar(sizeof...(tail) ? ' ' : '\n');
    W(tail...);
}
#ifdef SHIK
template<class T> void _dump(const char *s, T &&head) {
    cerr << s << "=" << head << endl;
}
template<class T, class... Args>
void _dump(const char *s, T &&head, Args &&... tail) {
    for (int c = 0; *s != ',' || c != 0; cerr << *s++) {
        if (*s == '(' || *s == '[' || *s == '{') c++;
        if (*s == ')' || *s == ']' || *s == '}') c--;
    }
    cerr << "=" << head << ", ";
    _dump(s + 1, tail...);
}
#define dump(...)                                                              \
    do {                                                                       \
        fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__);            \
        _dump(#__VA_ARGS__, __VA_ARGS__);                                      \
    } while (0)

template<class Iter> ostream &_out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    return s << "]";
}

template<class A, class B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
    return s << "(" << p.first << "," << p.second << ")";
}
template<class T> ostream &operator<<(ostream &s, const vector<T> &c) {
    return _out(s, ALL(c));
}
template<class T, size_t N>
ostream &operator<<(ostream &s, const array<T, N> &c) {
    return _out(s, ALL(c));
}
template<class T> ostream &operator<<(ostream &s, const set<T> &c) {
    return _out(s, ALL(c));
}
template<class A, class B> ostream &operator<<(ostream &s, const map<A, B> &c) {
    return _out(s, ALL(c));
}
#else
#define dump(...)
#endif

template<class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
    sort(begin(v), end(v), f);
    v.resize(unique(begin(v), end(v)) - begin(v));
}

template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

template<int MOD>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt(long long _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt operator-() const { return {x == 0 ? 0 : MOD-x}; }
    ModInt& operator+=(ModInt rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (long long)x * rhs.x % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        return *this *= rhs.inv();
    }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    ModInt inv() const {
        // should work for non-prime MOD if gcd(x, MOD) = 1
        int a = x, b = MOD, u = 1, v = 0;
        while (b != 0) {
            int t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        return u;
    }
    ModInt pow(long long e) {
        ModInt r = 1, p = *this;
        while (e) {
            if (e & 1) r *= p;
            p *= p;
            e >>= 1;
        }
        return r;
    }
    bool operator==(ModInt rhs) { return x == rhs.x; }
    bool operator!=(ModInt rhs) { return x != rhs.x; }
    bool operator<(ModInt rhs) { return x < rhs.x; }
    bool operator<=(ModInt rhs) { return x <= rhs.x; }
    bool operator>(ModInt rhs) { return x > rhs.x; }
    bool operator>=(ModInt rhs) { return x >= rhs.x; }
    friend ostream& operator<<(ostream &os, ModInt i) { return os << i.x; }
};

const int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

const int N=1e5+10;
const int C=11;
int n,m,g,gc;
VI e[N];

void dfs( int p ) {
    for ( int i:e[p] ) {
        auto it=find(ALL(e[i]),p);
        e[i].erase(it);
        dfs(i);
    }
}

mint dp[N][3][C],dq[3][C];
void go( int p ) {
    for ( int i:e[p] ) go(i);
    auto *me=dp[p];
    me[0][0]=g-1;
    me[1][1]=1;
    me[2][0]=m-g;
    for ( int i:e[p] ) {
        memset(dq,0,sizeof(dq));
        for ( int j=gc; j>=0; j-- ) REP1(k,0,gc-j) {
            mint t0=dp[i][0][k]+dp[i][1][k]+dp[i][2][k];
            mint t1=dp[i][0][k];
            mint t2=dp[i][0][k]+dp[i][2][k];
            dq[0][j+k]+=me[0][j]*t0;
            if ( j>0 ) dq[1][j+k]+=me[1][j]*t1;
            dq[2][j+k]+=me[2][j]*t2;
        }
        memcpy(me,dq,sizeof(dq));
    }
    // REP(i,3) REP1(j,0,gc) dump(p,i,j,dp[p][i][j]);
}

int main() {
    R(n,m);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    R(g,gc);
    dfs(1);
    go(1);
    mint ans=0;
    REP(i,3) REP1(j,0,gc) ans+=dp[1][i][j];
    W(ans);
    return 0;
}