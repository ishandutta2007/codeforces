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
char s[N];
string t[8];
int main() {
    int n=strlen(gets(s));
    if ( strchr(s,'0') ) return puts("YES\n0"),0;
    REP(i,n) {
        int x=s[i]-'0';
        string nt[8];
        nt[x%8]=s[i];
        REP(j,8) if ( !t[j].empty() ) {
            int k=(j*10+x)%8;
            nt[k]=t[j]+s[i];
        }
        REP(j,8) if ( t[j].empty() ) t[j]=nt[j];
    }
    if ( t[0].empty() ) puts("NO");
    else printf("YES\n%s\n",t[0].c_str());
    return 0;
}