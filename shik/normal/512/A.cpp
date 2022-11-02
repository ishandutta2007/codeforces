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
#define L 110

char s[N][L];
bool e[26][26];
int main() {
    int n;
    RI(n);
    REP(i,n) scanf("%s",s[i]);
    REP(i,n-1) {
        int j=0;
        while ( s[i][j]==s[i+1][j] ) j++;
        if ( s[i][j]=='\0' ) continue;
        if ( s[i+1][j]=='\0' ) {
            puts("Impossible");
            return 0;
        }
        e[s[i][j]-'a'][s[i+1][j]-'a']=1;
    }
    string ans;
    bool vis[26]={};
    REP(i,26) {
        bool found=0;
        REP(j,26) if ( !vis[j] ) {
            bool ok=1;
            REP(k,26) if ( e[k][j] && !vis[k] ) ok=0;
            if ( ok ) {
                found=1;
                vis[j]=1;
                ans+=char('a'+j);
                break;
            }
        }
        if ( !found ) {
            puts("Impossible");
            return 0;
        }
    }
    puts(ans.c_str());
    return 0;
}