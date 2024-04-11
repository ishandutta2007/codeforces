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
const int MOD=1e9+7;

char s[N];
char l[N];
string r[N];
LL pw[N],len[10],val[10];

PII shik( const char *str ) {
    int m=strlen(str);
    LL p=1,v=0;
    for ( int i=m-1; i>=0; i-- ) {
        int d=str[i]-'0';
        v=(v+p*val[d])%MOD;
        p=p*len[d]%MOD;
    }
    return MP(p,v);
}

int main() {
    gets(s);
    int n;
    RI(n);
    REP(i,n) {
        static char buf[N];
        scanf(" %c->",l+i);
        int ch,m=0;
        while ( (ch=getchar())!='\n' ) buf[m++]=ch;
        buf[m]=0;
        r[i]=buf;
    }
    pw[0]=1;
    REP1(i,1,N-1) pw[i]=pw[i-1]*10%MOD;
    REP(i,10) {
        len[i]=10;
        val[i]=i;
    }
    for ( int i=n-1; i>=0; i-- ) {
        auto now=shik(r[i].c_str());
        len[l[i]-'0']=now.first;
        val[l[i]-'0']=now.second;
    }
    auto ans=shik(s);
    printf("%d\n",ans.second);
    return 0;
}