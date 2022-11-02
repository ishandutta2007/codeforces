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

#define N 100010
int a[N];
int main() {
    int n;
    scanf("%d",&n);
    REP(i,n) scanf("%d",a+i);
    sort(a,a+n);
    LL u=0,d=n;
    REP(i,n) u+=a[i];
    REP(i,n-1) u+=2LL*(i+1)*(n-i-1)*(a[i+1]-a[i]);
    LL g=__gcd(u,d);
    u/=g; d/=g;
    cout << u << " " << d << endl;
    return 0;
}