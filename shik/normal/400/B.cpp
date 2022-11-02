// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
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

#define N 1010
int n,m;
char s[N][N];
int main() {
    RI(n,m);
    REP(i,n) scanf("%s",s[i]);
    set<int> st;
    REP(i,n) {
        char *pg=strchr(s[i],'G');
        char *ps=strchr(s[i],'S');
        if ( pg>ps ) {
            puts("-1");
            return 0;
        }
        st.insert(ps-pg);
    }
    printf("%d\n",SZ(st));
    return 0;
}