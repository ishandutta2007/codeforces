// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define ALL(x) begin(x),end(x)
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
char s[N],t[N];
const char good[]="AHIMOTUVWXY";
int main() {
    int n=strlen(gets(s));
    strcpy(t,s);
    reverse(t,t+n);
    bool flg=1;
    if ( strcmp(s,t)!=0 ) flg=0;
    for ( int i=0; s[i]; i++ ) if ( !strchr(good,s[i]) ) flg=0;
    puts(flg?"YES":"NO");
    return 0;
}