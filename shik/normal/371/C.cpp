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
#define REP(i,n) for (int i=0; i<(int)(n); i++)
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

#define N 110
char s[N];
int c[3],n[3],p[3];
LL money;
bool chk( LL m ) {
    LL t[3]={};
    REP(i,3) t[i]=max(m*c[i]-n[i],0LL);
    LL need=0;
    REP(i,3) need+=p[i]*t[i];
    return need<=money;
}
int main() {
    scanf("%s",s);
    REP(i,3) RI(n[i]);
    REP(i,3) RI(p[i]);
    cin>>money;
    for ( int i=0; s[i]; i++ ) {
        if ( s[i]=='B' ) c[0]++;
        else if ( s[i]=='S' ) c[1]++;
        else c[2]++;
    }
    LL l=0,r=1e13;
    while ( l!=r ) {
        LL m=(l+r+1)/2;
        if ( chk(m) ) l=m;
        else r=m-1;
    }
    cout << l << endl;
    return 0;
}