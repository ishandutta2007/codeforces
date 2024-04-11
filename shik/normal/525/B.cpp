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
char s[N];
int a[N];
int main() {
    int n=strlen(gets(s));
    int m;
    RI(m);
    REP(i,m) RI(a[i]);
    sort(a,a+m);
    for ( int i=0,j=0; i<n/2; i++ ) {
        while ( j<m && a[j]-1<=i ) j++;
        if ( j&1 ) swap(s[i],s[n-i-1]);
    }
    puts(s);
    return 0;
}