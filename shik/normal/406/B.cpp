// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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

#define N 1000010
int n,x[N],m,y[N];
bool take[N];
int main() {
    RI(n);
    REP1(i,1,n) RI(x[i]);
    REP1(i,1,n) take[x[i]]=1;
    LL s=0;
    REP1(i,1,n) s+=x[i]-1;
    REP1(i,1,n) {
        int t=1000000-x[i]+1;
        if ( !take[t] ) {
            take[t]=1;
            y[++m]=t;
            s-=1000000-t;
        }
    }
    REP1(i,1,1000000) {
        if ( s<=0 ) break;
        if ( take[i] || take[1000000-i+1] ) continue;
        take[i]=take[1000000-i+1]=1;
        y[++m]=i;
        y[++m]=1000000-i+1;
        s-=999999;
    }
    assert(s==0);
    printf("%d\n",m);
    REP1(i,1,m) printf("%d%c",y[i],i==m?'\n':' ');
    return 0;
}