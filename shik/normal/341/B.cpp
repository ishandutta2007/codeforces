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
int n,a[N],lis[N],m;
int main() {
    scanf("%d",&n);
    REP(i,n) scanf("%d",a+i);
    lis[m++]=0;
    REP(i,n) {
        if ( a[i]>lis[m-1] ) lis[m++]=a[i];
        else *lower_bound(lis,lis+m,a[i])=a[i];
    }
    printf("%d\n",m-1);
    return 0;
}