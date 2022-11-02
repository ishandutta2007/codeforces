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

#define N 3010
int n,a[N],b[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    REP(i,n) b[i]=a[i];
    sort(b,b+n);
    vector<PII> sol;
    REP(i,n) {
        if ( a[i]==b[i] ) continue;
        REP1(j,i+1,n-1) if ( a[j]==b[i] ) {
            sol.PB(MP(i,j));
            swap(a[i],a[j]);
            break;
        }
    }
    printf("%d\n",SZ(sol));
    REP(i,SZ(sol)) printf("%d %d\n",sol[i].first,sol[i].second);
    return 0;
}