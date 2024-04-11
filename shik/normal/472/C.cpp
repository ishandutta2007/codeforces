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

#define N 100010
string s[N][2];
int p[N];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    REP(i,n) cin>>s[i][0]>>s[i][1];
    REP(i,n) if ( s[i][0]>s[i][1] ) swap(s[i][0],s[i][1]);
    REP(i,n) {
        cin>>p[i];
        p[i]--;
    }
    string last;
    REP(ii,n) {
        int i=p[ii];
        if ( s[i][0]>last ) last=s[i][0];
        else if ( s[i][1]>last ) last=s[i][1];
        else {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}