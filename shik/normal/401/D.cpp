// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for (auto it=begin(c); it!=end(c); it++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
/// }}}

template<size_t sz,class Tk=int,class Tv=int,Tv dv=0>
struct HT {
    int n,pos[sz]; Tk key[sz]; Tv val[sz];
    void clear() { n=0; memset(pos,0,sizeof(pos)); }
    int hash( const Tk &x ) { return x%sz; }
    bool eq( const Tk &a, const Tk &b ) { return a==b; }
    Tv& operator[]( Tk p ) {
        int h=hash(p);
        while ( pos[h] ) {
            if ( eq(key[pos[h]],p) ) return val[pos[h]];
            if ( ++h==sz ) h=0;
        }
        key[pos[h]=++n]=p;
        return val[n]=dv;
    }
    Tv get( Tk p ) {
        int h=hash(p);
        while ( pos[h] ) {
            if ( eq(key[pos[h]],p) ) return val[pos[h]];
            if ( ++h==sz ) h=0;
        }
        return dv;
    }
};
HT<25165843,LL,LL,-1> dp;

inline int get( LL s, int i ) { return (s>>(5*i))&31; }
inline LL mak( int i ) { return 1LL<<(5*i); }

int m;
LL go( LL s, int r ) {
    if ( s==0 ) return r==0;
    LL &ret=dp[s*100+r];
    if ( ret!=-1 ) return ret;
    ret=0;
    REP(i,10) if ( get(s,i) ) ret+=go(s-mak(i),(r*10+i)%m);
    return ret;
}
int main() {
    LL n;
    cin>>n>>m;
    stringstream ss;
    char buf[20];
    ss << n;
    ss >> buf;
    int len=strlen(buf);
    LL s=0;
    REP(i,10) s|=(LL)count(buf,buf+len,'0'+i)<<(5*i);
    LL ans=0;
    REP1(i,1,9) if ( get(s,i) ) ans+=go(s-mak(i),i%m);
    cout<<ans<<endl;
    return 0;
}