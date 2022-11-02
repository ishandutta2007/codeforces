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

LL f( LL x ) {
    return x*(x-1)/2;
}
int main() {
    LL n,m;
    cin>>n>>m;
    LL a1=(m-n%m)*f(n/m)+n%m*f(n/m+1);
    LL a2=f(n-m+1);
    cout<<a1<<" "<<a2<<endl;
    return 0;
}