// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

int ans=0;
VI sol;
void update( int l, int r ) {
    if ( r-l<ans ) return;
    if ( r-l>ans ) sol.clear();
    ans=r-l;
    sol.PB(l);
}

#define N 300010
int a[N],b[19][N];

int main() {
    int n;
    RI(n);
    REP1(i,1,n) RI(a[i]);

    int lgn=__lg(n);
    REP1(i,1,n) b[0][i]=a[i];
    for ( int i=1; i<=lgn; i++ ) {
        int l=(1<<(i-1));
        int upj=n-l-l+1;
        for ( int j=1; j<=upj; j++ ) b[i][j]=__gcd(b[i-1][j],b[i-1][j+l]);
    }

    REP1(i,1,n) {
        int l=i,r=i;
        for ( int j=lgn; j>=0; j-- ) if ( l-(1<<j)>=1 && b[j][l-(1<<j)]%a[i]==0 ) l-=(1<<j);
        for ( int j=lgn; j>=0; j-- ) if ( r+(1<<j)<=n && b[j][r+1]%a[i]==0 ) r+=(1<<j);
        //printf("%d: (%d,%d)\n",i,l,r);
        update(l,r);
    }
    
    sort(sol.begin(),sol.end());
    sol.erase(unique(sol.begin(),sol.end()),sol.end());
    printf("%d %d\n",SZ(sol),ans);
    FOR(it,sol) printf("%d%c",*it,*it==sol.back()?'\n':' ');
    return 0;
}