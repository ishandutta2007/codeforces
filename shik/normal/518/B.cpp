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

char s[N],t[N];
int main() {
    int n=strlen(gets(s));
    int m=strlen(gets(t));
    int cnt[130]={};
    REP(i,m) cnt[(int)t[i]]++;
    int a1=0,a2=0;
    REP(i,n) {
        int ch=s[i];
        if ( cnt[ch]>0 ) {
            cnt[ch]--;
            a1++;
            s[i]=0;
        }
    }
    REP(i,n) if ( s[i] ) {
        int ch=s[i];
        if ( cnt[ch^32]>0 ) {
            cnt[ch^32]--;
            a2++;
        }
    }
    printf("%d %d\n",a1,a2);
    return 0;
}