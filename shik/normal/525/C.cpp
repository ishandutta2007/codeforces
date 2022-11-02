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

const int N=1e5+10;
int n,a[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    LL ans=0;
    for ( int i=0,j; i<n; i=j ) {
        VI v;
        for ( j=i; j+1<n && SZ(v)<2; j++ ) {
            if ( a[j]==a[j+1] ) {
                v.PB(a[j]);
                j++;
            } else if ( a[j]-1==a[j+1] ) {
                v.PB(a[j]-1);
                j++;
            }
        }
        if ( SZ(v)==2 ) {
            ans+=1LL*v[0]*v[1];
        } else {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}