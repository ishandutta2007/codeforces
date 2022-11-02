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

#define N 1000010
int n;
char s[N];

bool check( int obs ) {
    int l=0,r=0,x=0;
    bool good=0;
    REP(i,n) {
        int ox=x;
        if ( s[i]=='L' ) x--;
        else x++;
        good=0;
        if ( x==obs ) x=ox;
        if ( x<l ) l=x,good=1;
        if ( x>r ) r=x,good=1;
    }
    return good;
}

int main() {
    n=strlen(gets(s));
    if ( check(N) ) return puts("1"),0;
    if ( s[n-1]=='L' ) {
        if ( !check(1) ) return puts("0"),0;
        int l=1,r=N;
        while ( l!=r ) {
            int m=(l+r+1)/2;
            if ( check(m) ) l=m;
            else r=m-1;
        }
        printf("%d\n",l);
    } else {
        if ( !check(-1) ) return puts("0"),0;
        int l=1,r=N;
        while ( l!=r ) {
            int m=(l+r+1)/2;
            if ( check(-m) ) l=m;
            else r=m-1;
        }
        printf("%d\n",l);
    }
    return 0;
}