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
char s1[N],s2[N];
int cnt[128];

int main() {
    int n1=strlen(gets(s1));
    int n2=strlen(gets(s2));
    bool can_au=1;
    for ( int i1=0,i2=0; i2<n2; i2++ ) {
        while ( i1<n1 && s1[i1]!=s2[i2] ) i1++;
        if ( i1==n1 ) {
            can_au=0;
            break;
        }
        i1++;
    }
    if ( can_au ) return puts("automaton"),0;
    REP(i,n1) cnt[(int)s1[i]]++;
    REP(i,n2) cnt[(int)s2[i]]--;
    bool can_ar=1;
    REP(i,128) if ( cnt[i]!=0 ) can_ar=0;
    if ( can_ar ) return puts("array"),0;
    bool can_bo=1;
    REP(i,128) if ( cnt[i]<0 ) can_bo=0;
    if ( can_bo ) return puts("both"),0;
    puts("need tree");
    return 0;
}