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

const int N=1e6;
char s[N];
int main() {
    int n;
    RI(n);
    scanf("%s",s);
    int cnt[26]={},ans=0;
    for ( int i=0; i<2*n-2; i+=2 ) {
        int k=s[i]-'a';
        int d=s[i+1]-'A';
        cnt[k]++;
        if ( cnt[d]==0 ) ans++;
        else cnt[d]--;
    }
    printf("%d\n",ans);
    return 0;
}