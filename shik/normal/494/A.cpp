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
char s[N];
int main() {
    int n=strlen(gets(s));
    int last=-1;
    int zz=0;
    REP(i,n) if ( s[i]=='#' ) {
        zz++;
        s[i]=')';
        last=i;
    }
    int cl=count(s,s+n,'(');
    int cr=count(s,s+n,')');
    if ( cr>cl ) return puts("-1"),0;
    int cnt=0;
    REP(i,n) {
        if ( s[i]=='(' ) cnt++;
        else cnt--;
        if ( i==last ) cnt-=cl-cr;
        if ( cnt<0 ) return puts("-1"),0;
    }
    if ( cnt!=0 ) return puts("-1"),0;
    REP(i,zz-1) puts("1");
    printf("%d\n",cl-cr+1);
    return 0;
}