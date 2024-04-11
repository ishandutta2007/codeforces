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
} while (0);

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
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 100010
int n,m,k;
VI e[N];
bool ban[N],bye[N];
int cnt[N];
inline double shik( int p ) {
    return 1.0*cnt[p]/e[p].size();
}
bool chk( double mm ) {
    // dump(mm);
    priority_queue<pair<double,int>> q;
    memset(cnt,0,sizeof(cnt));
    memset(bye,0,sizeof(bye));
    REP1(i,1,n) if ( !ban[i] )
        for ( int j:e[i] ) if ( !ban[j] ) cnt[i]++;
    REP1(i,1,n) if ( !ban[i] ) q.push({-shik(i),i});
    while ( !q.empty() && -q.top().first<mm ) {
        int p=q.top().second;
        q.pop();
        if ( bye[p] ) continue;
        bye[p]=1;
        for ( int i:e[p] ) if ( !ban[i] && !bye[i] ) {
            cnt[i]--;
            // dump(mm,p,i,cnt[i]);
            q.push({-shik(i),i});
        }
    }
    REP1(i,1,n) if ( !ban[i] && !bye[i] ) {
        // dump(mm,i);
        return 1;
    }
    return 0;
}

int main() {
    RI(n,m,k);
    REP(i,k) {
        int x;
        RI(x);
        ban[x]=1;
    }
    REP(i,m) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    double ll=0,rr=1;
    REP(i,40) {
        double mm=(ll+rr)/2;
        if ( chk(mm) ) ll=mm;
        else rr=mm;
    }
    dump(ll);
    chk(ll);
    VI sol;
    REP1(i,1,n) if ( !ban[i] && !bye[i] ) {
        // dump(i,shik(i));
        sol.PB(i);
    }
    // dump(SZ(e[1]),cnt[1]);
    printf("%d\n",SZ(sol));
    REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
    return 0;
}