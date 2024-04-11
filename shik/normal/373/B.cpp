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

LL p10[20]={1};
int len( LL x ) {
    int l=0;
    while ( x ) {
        l++;
        x/=10;
    }
    return l;
}
int main() {
    LL w,m,k;
    cin>>w>>m>>k;
    w/=k;
    REP1(i,1,18) p10[i]=p10[i-1]*10;
    LL ans=0;
    while ( w>0 ) {
        int l=len(m);
        if ( (p10[l]-m)*l <= w ) {
            ans+=p10[l]-m;
            w-=(p10[l]-m)*l;
            m=p10[l];
        } else {
            ans+=w/l;
            w=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}