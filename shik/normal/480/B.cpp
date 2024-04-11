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

#define N 100010
int n,l,x,y,a[N];

bool has( int v ) {
    return binary_search(a,a+n,v);
}

bool okx,oky;
bool check_0() {
    REP(i,n) {
        if ( !okx && has(a[i]+x) ) okx=1;
        if ( !oky && has(a[i]+y) ) oky=1;
    }
    return okx && oky;
}

bool good( int v ) {
    if ( v<0 || v>l ) return 0;
    if ( !okx && !has(v-x) && !has(v+x) ) return 0;
    if ( !oky && !has(v-y) && !has(v+y) ) return 0;
    printf("%d\n%d\n",1,v);
    return 1;
}

bool check_1() {
    REP(i,n) {
        if ( good(a[i]-x) ) return 1;
        if ( good(a[i]+x) ) return 1;
        if ( good(a[i]-y) ) return 1;
        if ( good(a[i]+y) ) return 1;
    }
    return 0;
}

int main() {
    RI(n,l,x,y);
    REP(i,n) RI(a[i]);
    if ( check_0() ) {
        puts("0");
    } else if ( check_1() ) {
    } else {
        puts("2");
        printf("%d %d\n",x,y);
    }
    return 0;
}