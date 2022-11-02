// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define PER(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define PER1(i,b,a) for (int i=(int)(b); i>=(int)(a); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// }}}

inline int bit( int x, int i ) { return (x>>i)&1; }

#define N 1010
int n,x[N];
vector<PII> sol;
void move( int a, int b ) {
    sol.PB(MP(b,a));
    x[a]-=x[b];
    x[b]*=2;
}
void solve( int a, int b, int c ) {
    while ( x[a] && x[b] && x[c] ) {
        REP(i,3) {
            if ( x[a]>x[b] ) swap(a,b);
            if ( x[b]>x[c] ) swap(b,c);
        }
        int q=x[b]/x[a],i=0;
        while ( x[b]>=x[a] ) {
            if ( bit(q,i++) ) move(b,a);
            else move(c,a);
        }
    }
}
int main() {
    scanf("%d",&n);
    REP1(i,1,n) scanf("%d",x+i);
    int a=0,b=0,c=0;
    REP1(i,1,n) {
        if ( x[a]==0 ) a=i;
        else if ( x[b]==0 ) b=i;
        else if ( x[c]==0 ) c=i;
        solve(a,b,c);
    }
    if ( !!x[a] + !!x[b] + !!x[c] != 2 ) puts("-1");
    else {
        printf("%d\n",SZ(sol));
        FOR(it,sol) printf("%d %d\n",it->first,it->second);
    }
    return 0;
}