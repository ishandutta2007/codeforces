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

const int N=100010;
const int MOD=1e9+7;

int n;
char s[N];
int main() {
    scanf("%d%s",&n,s);
    int cnt[26]={};
    REP(i,n) cnt[s[i]-'A']++;
    int mx=*max_element(cnt,cnt+26);
    int c=0;
    REP(i,26) if ( cnt[i]==mx ) c++;
    int ans=1;
    REP(i,n) ans=1LL*ans*c%MOD;
    printf("%d\n",ans);
    return 0;
}