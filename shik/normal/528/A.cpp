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

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

struct XD {
    set<int> s;
    multiset<int> h;
    void init( int n ) {
        s.insert(0);
        s.insert(n);
        h.insert(n);
    }
    int max() {
        return *h.rbegin();
    }
    void ins( int p ) {
        auto it=s.lower_bound(p);
        auto jt=it; it--;
        h.erase(h.find(*jt-*it));
        h.insert(p-*it);
        h.insert(*jt-p);
        s.insert(p);
    }
} sx,sy;

int main() {
    int w,h,n;
    RI(w,h,n);
    sx.init(w);
    sy.init(h);
    REP(i,n) {
        char ch;
        int pos;
        scanf(" %c%d",&ch,&pos);
        if ( ch=='V' ) sx.ins(pos);
        else sy.ins(pos);
        int mx=sx.max();
        int my=sy.max();
        LL ans=1LL*mx*my;
        printf("%lld\n",ans);
    }
    return 0;
}