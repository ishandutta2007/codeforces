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

#define N 50010
#define C 300
char s[N];
map<string,vector<int>> app;

int solve( string a, string b ) {
    if ( !app.count(a) || !app.count(b) ) return -1;
    if ( SZ(app[a])>SZ(app[b]) ) swap(a,b);
    static map<pair<string,string>,int> memo;
    if ( memo.count(MP(a,b)) ) return memo[MP(a,b)];
    int la=SZ(a),lb=SZ(b);
    auto &va=app[a],&vb=app[b];
    int ans=1e9;
    auto chk=[&]( int i, int j ) {
        int now=max(va[i]+la,vb[j]+lb)-min(va[i],vb[j]);
        ans=min(ans,now);
    };
    if ( SZ(va)>=C ) {
        for ( int i=0,j=0; i<SZ(va); i++ ) {
            while ( j<SZ(vb) && vb[j]<va[i] ) {
                chk(i,j);
                j++;
            }
            if ( j<SZ(vb) ) chk(i,j);
        }
    } else {
        REP(i,SZ(va)) {
            int j=lower_bound(ALL(vb),va[i])-vb.begin();
            if ( j<SZ(vb) ) chk(i,j);
            j--;
            if ( j>=0 ) chk(i,j);
        }
    }
    return memo[MP(a,b)]=ans;
}

int main() {
    int n=strlen(gets(s));
    REP(i,n) {
        string t;
        for ( int j=0; j<4 && i+j<n; j++ ) {
            t+=s[i+j];
            app[t].PB(i);
        }
    }
    int q;
    RI(q);
    while ( q-- ) {
        char a[10],b[10];
        scanf("%s%s",a,b);
        int ans=solve(a,b);
        printf("%d\n",ans);
    }
    return 0;
}