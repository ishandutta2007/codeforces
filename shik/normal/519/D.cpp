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
int v[26];
char s[N];
LL ss[N];
int main() {
    REP(i,26) RI(v[i]);
    scanf("%s",s+1);
    int n=strlen(s+1);
    REP1(i,1,n) ss[i]=ss[i-1]+v[s[i]-'a'];
    LL ans=0;
    map<pair<LL,char>,int> mp;
    REP1(i,1,n) {
        auto p=MP(ss[i-1],s[i]);
        if ( mp.count(p) ) ans+=mp[p];
        mp[MP(ss[i],s[i])]++;
    }
    cout<<ans<<endl;
    return 0;
}