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

#define N 2014
int f[N];
int main() {
    int n,k;
    RI(n,k);
    REP(i,n) RI(f[i]);
    sort(f,f+n);
    reverse(f,f+n);
    int ans=0;
    for ( int i=0; i<n; i+=k ) ans+=f[i]-1;
    printf("%d\n",2*ans);
    return 0;
}