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

#define N 110
char s[N],t[N];
int main() {
    gets(s);
    gets(t);
    int n=strlen(s);
    s[n-1]++;
    for ( int i=n-1; i>0; i-- ) if ( s[i]>'z' ) {
        s[i]='a';
        s[i-1]++;
    }
    if ( s[0]>'z' || strcmp(s,t)>=0 ) puts("No such string");
    else puts(s);
    return 0;
}