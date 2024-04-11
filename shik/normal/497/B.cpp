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

#define N 200010
int n,a[N],s1[N],s2[N],is1[N],is2[N];

vector<PII> sol;
void chk_t( int t ) {
    int i=1,c1=0,c2=0,last=0;
    while ( i<=n ) {
        int j1=is1[s1[i-1]+t];
        int j2=is2[s2[i-1]+t];
        if ( !j1 && !j2 ) return;
        if ( !j2 || (j1 && j1<j2) ) {
            i=j1+1;
            c1++;
            last=1;
        } else {
            i=j2+1;
            c2++;
            last=2;
        }
    }
    if ( c1==c2 ) return;
    if ( c1>c2 ) {
        if ( last!=1 ) return;
        sol.PB(MP(c1,t));
    } else {
        if ( last!=2 ) return;
        sol.PB(MP(c2,t));
    }
}

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) s1[i]=s1[i-1]+(a[i]==1);
    REP1(i,1,n) s2[i]=s2[i-1]+(a[i]==2);
    REP1(i,1,n) if ( !is1[s1[i]] ) is1[s1[i]]=i;
    REP1(i,1,n) if ( !is2[s2[i]] ) is2[s2[i]]=i;
    REP1(i,1,n) chk_t(i);
    sort(ALL(sol));
    printf("%d\n",SZ(sol));
    FOR(it,sol) printf("%d %d\n",it->first,it->second);
    return 0;
}