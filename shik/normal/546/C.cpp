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

LL input( int &n ) {
    RI(n);
    LL x=0;
    REP(i,n) {
        LL y;
        cin>>y;
        x|=y<<(4*i);
    }
    return x;
}

int main() {
    int n,n1,n2;
    RI(n);
    LL x1=input(n1);
    LL x2=input(n2);
    set<pair<LL,LL>> vis;
    int round=0;
    while ( 1 ) {
        auto st=MP(x1,x2);
        if ( vis.count(st) ) {
            puts("-1");
            return 0;
        }
        vis.insert(st);
        round++;
        LL y1=x1&0xF; x1>>=4; n1--;
        LL y2=x2&0xF; x2>>=4; n2--;
        if ( y1<y2 ) {
            x2|=y1<<(4*n2++);
            x2|=y2<<(4*n2++);
        } else {
            x1|=y2<<(4*n1++);
            x1|=y1<<(4*n1++);
        }
        if ( n1==0 ) {
            printf("%d 2\n",round);
            break;
        } else if ( n2==0 ) {
            printf("%d 1\n",round);
            break;
        }
    }
    return 0;
}