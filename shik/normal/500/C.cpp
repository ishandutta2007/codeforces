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

#define N 514
#define M 1234
int n,m,w[N],b[M];
bool vis[N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(w[i]);
    REP1(i,1,m) RI(b[i]);
    VI a;
    REP1(i,1,m) {
        int x=b[i];
        if ( vis[x] ) continue;
        vis[x]=1;
        a.PB(x);
    }
    int ans=0;
    REP1(i,1,m) {
        int x=b[i];
        REP(j,SZ(a)) {
            if ( a[j]==x ) {
                for ( int k=j; k>0; k-- ) swap(a[k],a[k-1]);
                break;
            } else {
                ans+=w[a[j]];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}