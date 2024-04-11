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

#define N 2010
int n,a[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    while ( 1 ) {
        bool done=1;
        for ( int i=0; i<n; i++ ) {
            int c[2]={};
            for ( int j=0; j<i; j++ ) if ( a[i]<a[j] ) c[0]++;
            for ( int j=i+1; j<n; j++ ) if ( a[i]>a[j] ) c[0]++;
            for ( int j=0; j<i; j++ ) if ( -a[i]<a[j] ) c[1]++;
            for ( int j=i+1; j<n; j++ ) if ( -a[i]>a[j] ) c[1]++;
            if ( c[0]>c[1] ) a[i]*=-1,done=0;
        }
        for ( int i=n-1; i>=0; i-- ) {
            int c[2]={};
            for ( int j=0; j<i; j++ ) if ( a[i]<a[j] ) c[0]++;
            for ( int j=i+1; j<n; j++ ) if ( a[i]>a[j] ) c[0]++;
            for ( int j=0; j<i; j++ ) if ( -a[i]<a[j] ) c[1]++;
            for ( int j=i+1; j<n; j++ ) if ( -a[i]>a[j] ) c[1]++;
            if ( c[0]>c[1] ) a[i]*=-1,done=0;
        }
        if ( done ) break;
    }
    int ans=0;
    for ( int i=0; i<n; i++ ) {
        int now=0;
        for ( int j=0; j<i; j++ ) if ( a[j]>a[i] ) now++;
        ans+=now;
    }
    printf("%d\n",ans);
    return 0;
}