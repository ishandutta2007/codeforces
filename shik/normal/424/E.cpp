// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

template<size_t sz,class Tk=int,class Tv=int>
struct HT {
    int n,pos[sz]; Tk key[sz]; Tv val[sz];
    int hash( const Tk &x ) {
        unsigned int h=0;
        FOR(it,x) h=h*131+*it;
        return h%sz;
    }
    bool eq( const Tk &a, const Tk &b ) { return a==b; }
    Tv& operator[]( Tk p ) {
        int h=hash(p);
        while ( pos[h] ) {
            if ( eq(key[pos[h]],p) ) return val[pos[h]];
            if ( ++h==sz ) h=0;
        }
        key[pos[h]=++n]=p;
        return val[n]=0;
    }
};

const double INF=1e10;
enum { R,G,B,X,O };

inline char make( char c[3] ) {
    return c[0]+5*c[1]+25*c[2];
}

inline char make( char c0, char c1, char c2 ) {
    return c0+5*c1+25*c2;
}

inline void ekam( char ch, char c[3] ) {
    c[0]=ch%5;
    c[1]=ch/5%5;
    c[2]=ch/25%5;
}

string nomalize( string s ) {
    string t;
    char c[3];
    REP(i,SZ(s)-1) {
        ekam(s[i],c);
        if ( c[0]>c[2] ) swap(c[0],c[2]);
        if ( c[1]<=X && ((c[0]<=X) ^ (c[2]<=X)) ) c[1]=X;
        if ( c[1]<=X && (c[0]<=X || c[2]<=X) ) t+=make(c);
    }
    ekam(s.back(),c);
    if ( c[0]>c[2] ) swap(c[0],c[2]);
    t+=make(c);
    sort(t.begin(),t.end()-1);
    return t;
}

void take( string s, int i, int j, vector<string> v[3] ) {
    char c[3];
    ekam(s[i],c);
    int ch=c[j];
    c[j]=O;
    s[i]=make(c);
    ekam(s.back(),c);
    if ( c[0]==O || c[1]==O || c[2]==O ) s.pop_back();
    else c[0]=c[1]=c[2]=O;
    REP(k,3) if ( c[k]==O ) {
        c[k]=ch;
        v[ch].PB(s+make(c));
        c[k]=O;
    }
}

HT<12582917,string,double> dp;

int prob[3]={1,2,2};
double go( string s ) {
    s=nomalize(s);
    if ( SZ(s)==1 ) return 0;
    double &ret=dp[s];
    if ( ret!=0 ) return ret;
    vector<string> ns[3];
    REP(i,SZ(s)-1) {
        char c[3];
        ekam(s[i],c);
        if ( c[0]<=X ) take(s,i,0,ns);
        if ( c[2]<=X ) take(s,i,2,ns);
        if ( c[0]<=X && c[2]<=X ) take(s,i,1,ns);
    }
    int black=1;
    REP(i,3) {
        if ( ns[i].empty() ) {
            black+=prob[i];
            continue;
        }
        double sml=INF;
        FOR(it,ns[i]) sml=min(sml,go(*it));
        ret+=prob[i]*sml;
    }
    if ( black==6 ) return ret=0;
    ret/=6;
    ret++;
    ret/=(1-black/6.0);
    return ret;
}

int main() {
    int n;
    RI(n);
    string t;
    while ( n-- ) {
        char s[4];
        scanf("%s",s);
        const char *cs="RGB";
        REP(i,3) s[i]=strchr(cs,s[i])-cs;
        t+=make(s);
    }
    double ans=go(t);
    printf("%.9f\n",ans);
    return 0;
}