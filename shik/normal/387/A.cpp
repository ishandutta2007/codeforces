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

int main() {
    int h1,m1,h2,m2;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    int s1=h1*60+m1;
    int s2=h2*60+m2;
    int s=s1-s2;
    if ( s<0 ) s+=24*60;
    printf("%02d:%02d\n",s/60,s%60);
    return 0;
}