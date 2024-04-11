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

#define N 1010
int n,m;
char s[N][N];
bool gap[N];
int main() {
    RI(n,m);
    REP(i,n) scanf("%s",s[i]);
    int ans=0;
    REP(i,m) {
        bool good=1;
        REP(j,n-1) if ( !gap[j] && s[j][i]>s[j+1][i] ) good=0;
        if ( good ) {
            REP(j,n-1) if ( s[j][i]<s[j+1][i] ) gap[j]=1;
        } else {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}