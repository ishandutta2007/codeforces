// {{{ by shik
#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

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

struct Seg {
    set<int> s[4*N];
    void ins( int id, int l, int r, int ql, int qr, int qv ) {
        if ( ql<=l && r<=qr ) {
            s[id].insert(qv);
            return;
        }
        int m=(l+r)/2;
        if ( ql<=m ) ins(id*2,l,m,ql,qr,qv);
        if ( qr>m ) ins(id*2+1,m+1,r,ql,qr,qv);
    }
    void del( int id, int l, int r, int ql, int qr, int qv ) {
        if ( ql<=l && r<=qr ) {
            s[id].erase(qv);
            return;
        }
        int m=(l+r)/2;
        if ( ql<=m ) del(id*2,l,m,ql,qr,qv);
        if ( qr>m ) del(id*2+1,m+1,r,ql,qr,qv);
    }
    int ask( int id, int l, int r, int qx ) {
        int mx=-1;
        while ( 1 ) {
            if ( !s[id].empty() ) mx=max(mx,*s[id].rbegin());
            if ( l==r ) break;
            int m=(l+r)/2;
            if ( qx<=m ) {
                r=m;
                id*=2;
            } else {
                l=m+1;
                id=id*2+1;
            }
        }
        assert(mx>=0);
        return mx;
    }
} seg;

struct P {
    int t,l,r,s;
} p[N];

bool cmp_t( const P &a, const P &b ) {
    return a.t<b.t;
}

int h,w,n;
mint dp[N];
int main() {
    R(h,w,n);
    REP1(i,1,n) R(p[i].t,p[i].l,p[i].r,p[i].s);
    sort(p+1,p+n+1,cmp_t);
    dp[0]=1;
    seg.ins(1,1,w,1,w,0);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    REP1(i,1,n) {
        while ( !q.empty() && q.top().first<p[i].t ) {
            int id=q.top().second; q.pop();
            seg.del(1,1,w,p[id].l,p[id].r,id);
        }
        int x1=(p[i].l>1 ? p[i].l-1 : p[i].r+1);
        int x2=(p[i].r<w ? p[i].r+1 : p[i].l-1);
        int y1=seg.ask(1,1,w,x1);
        int y2=seg.ask(1,1,w,x2);
        dp[i]=dp[y1]+dp[y2];
        seg.ins(1,1,w,p[i].l,p[i].r,i);
        q.push({p[i].t+p[i].s,i});
        dump(i,x1,x2,y1,y2,dp[i]);
    }
    while ( !q.empty() && q.top().first<h+1 ) {
        int id=q.top().second; q.pop();
        seg.del(1,1,w,p[id].l,p[id].r,id);
    }
    mint ans=0;
    REP1(i,1,w) {
        int t=seg.ask(1,1,w,i);
        dump(i,t,dp[t]);
        ans+=dp[t];
    }
    W(ans);
    return 0;
}