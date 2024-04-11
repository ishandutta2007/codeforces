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

int q;
int main() {
    RI(q);
    map<string,string> m1,m2;
    while ( q-- ) {
        string a,b;
        cin>>a>>b;
        if ( !m2.count(a) ) {
            m1[a]=b;
            m2[b]=a;
        } else {
            m1[m2[a]]=b;
            m2[b]=m2[a];
            m2.erase(a);
        }
    }
    printf("%d\n",SZ(m1));
    FOR(it,m1) printf("%s %s\n",(it->first).c_str(),(it->second).c_str());
    return 0;
}