// {{{ by shik
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

uint32_t seed;
uint32_t my_rand() {
    return seed=seed*1103515245+12345;
}


const int N=150010;

struct Seg2 {
    int cov[4*N];
    void init( int id, int l, int r, int a[] ) {
        if ( l==r ) {
            cov[id]=a[l];
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m,a);
        init(id*2+1,m+1,r,a);
        cov[id]=0;
    }
    void push( int id ) {
        if ( !cov[id] ) return;
        cov[id*2]=cov[id];
        cov[id*2+1]=cov[id];
        cov[id]=0;
    }
    void ins( int id, int l, int r, int ql, int qr, int qv ) {
        // dump(id,l,r,ql,qr,qv);
        if ( ql<=l && r<=qr ) {
            cov[id]=qv;
            return;
        }
        push(id);
        int m=(l+r)/2;
        if ( ql<=m ) ins(id*2,l,m,ql,qr,qv);
        if ( qr>m ) ins(id*2+1,m+1,r,ql,qr,qv);
    }
    int ask( int id, int l, int r, int qx ) {
        while ( !cov[id] ) {
            int m=(l+r)/2;
            if ( qx<=m ) id*=2,r=m;
            else id=id*2+1,l=m+1;
        }
        return cov[id];
    }
} seg2;

struct Seg {
    static Seg mem[N*100],*pmem;
    int sum,add;
    Seg *lc,*rc;
    Seg():sum(0),add(0),lc(NULL),rc(NULL) {}
    void push() {
        assert(pmem-mem<N*100);
        if ( !lc ) lc=new (pmem++) Seg();
        if ( !rc ) rc=new (pmem++) Seg();
        // if ( rand()%1000==0 ) dump(pmem-mem);
        lc->add+=add;
        rc->add+=add;
        add=0;
    }
    int get_sum( int l, int r ) {
        return sum+(r-l+1)*add;
    }
    void pull( int l, int m, int r ) {
        sum=lc->get_sum(l,m)+rc->get_sum(m+1,r);
    }
    void ins( int l, int r, int ql, int qr, int qv ) {
        if ( ql<=l && r<=qr ) {
            add+=qv;
            return;
        }
        int m=(l+r)/2;
        push();
        if ( ql<=m ) lc->ins(l,m,ql,qr,qv);
        if ( qr>m ) rc->ins(m+1,r,ql,qr,qv);
        pull(l,m,r);
    }
    int ask( int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return get_sum(l,r);
        if ( !lc && !rc ) {
            int len=min(r,qr)-max(l,ql)+1;
            return len*add;
        }
        int m=(l+r)/2,ans=0;
        push();
        if ( ql<=m ) ans+=lc->ask(l,m,ql,qr);
        if ( qr>m ) ans+=rc->ask(m+1,r,ql,qr);
        pull(l,m,r);
        return ans;
    }
    void print( int l, int r ) {
        dump(l,r,sum,add);
        int m=(l+r)/2;
        if ( lc ) lc->print(l,m);
        if ( rc ) rc->print(m+1,r);
    }
} seg[N],Seg::mem[N*100],*Seg::pmem=Seg::mem;

struct P {
    int l,r,id;
};

#ifdef SHIK
ostream& operator <<( ostream &o, const P &p ) {
    return o<<MP(MP(p.l,p.r),p.id);
}
#endif

inline bool operator <( const P &a, const P &b ) {
    return a.l<b.l;
}

int n,m,per,a[N];

set<P> sp;
void ins_p( const P &p ) {
    // dump(p.l,p.r,p.id);
    seg[p.id].ins(1,n,p.l,p.r,1);
    sp.insert(p);
}
void del_p( const P &p ) {
    // dump(p.l,p.r,p.id);
    seg[p.id].ins(1,n,p.l,p.r,-1);
    sp.erase(p);
}

int main() {
    seed=time(0)^getpid()^(LL)&seed;
    R(n,m,per);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) ins_p(P{i,i,a[i]});
    seg2.init(1,1,n,a);
    while ( m-- ) {
        int op;
        R(op);
        if ( op==1 ) {
            int l,r,id;
            R(l,r,id);
            do {
                auto it=sp.lower_bound(P{l,0,0});
                if ( it==sp.begin() ) break;
                it--;
                if ( it->r<l ) {
                    assert(it->r==l-1);
                    break;
                }
                P np1{it->l,l-1,it->id};
                P np2{l,it->r,it->id};
                del_p(*it);
                ins_p(np2);
                ins_p(np1);
            } while ( 0 );
            while ( 1 ) {
                auto it=sp.lower_bound(P{l,0,0});
                if ( it==sp.end() || it->l>r ) break;
                if ( it->r<=r ) {
                    del_p(*it);
                } else {
                    P np{r+1,it->r,it->id};
                    del_p(*it);
                    ins_p(np);
                }
            }
            ins_p(P{l,r,id});
            seg2.ins(1,1,n,l,r,id);
            // dump(sp);
        } else if ( op==2 ) {
            int l,r;
            R(l,r);
            VI v;
            REP(i,100) {
                int x=l+my_rand()%(r-l+1);
                // auto it=--sp.upper_bound(P{x,0,0});
                // v.PB(it->id);
                v.PB(seg2.ask(1,1,n,x));
            }
            sort(ALL(v));
            v.resize(unique(ALL(v))-v.begin());
            VI ans;
            int gap=(per*(r-l+1)+99)/100;
            for ( int i:v ) {
                if ( seg[i].get_sum(1,n)<gap ) continue;
                int c=seg[i].ask(1,n,l,r);
                // dump(i,c);
                if ( c<gap ) continue;
                ans.PB(i);
                if ( SZ(ans)==100/per ) break;
            }
            if ( ans.empty() ) {
                W(0);
            } else {
                printf("%d ",SZ(ans));
                W(ans);
            }
        } else assert(0);
    }
    return 0;
}