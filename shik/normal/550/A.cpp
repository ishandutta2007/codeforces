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
    int a=-1,b=-1,c=-1,d=-1;
    REP(i,n) {
        if ( a==-1 && s[i]=='A' && s[i+1]=='B' ) a=i;
        if ( s[i]=='A' && s[i+1]=='B' ) b=i;
        if ( c==-1 && s[i]=='B' && s[i+1]=='A' ) c=i;
        if ( s[i]=='B' && s[i+1]=='A' ) d=i;
    }
    if ( a!=-1 && c!=-1 && (a+1<d || c+1<b) ) puts("YES");
    else puts("NO");
    return 0;
}