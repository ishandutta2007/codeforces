// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
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

#define N 210
char s[N];
int main() {
    int n;
    RI(n);
    scanf("%s",s);
    int c=count(s,s+n,'x')-n/2;
    printf("%d\n",abs(c));
    REP(i,n) {
        if ( c>0 && s[i]=='x' ) s[i]='X',c--;
        if ( c<0 && s[i]=='X' ) s[i]='x',c++;
    }
    puts(s);
    return 0;
}