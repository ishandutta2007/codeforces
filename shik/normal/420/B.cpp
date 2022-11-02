// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define ALL(x) begin(x),end(x)
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
int n,m,in[N],out[N],cnt[N],sc[N];
vector<int> rec[N];
int main() {
    RI(n,m);
    REP1(i,2,m+1) {
        char op;
        int id;
        scanf(" %c %d",&op,&id);
        if ( op=='+' ) {
            rec[id].PB(i);
        } else if ( op=='-' ) {
            if ( rec[id].empty() ) rec[id].PB(1);
            rec[id].PB(i);
        } else {
            printf("QQ op = [%c]\n",op);
        }
    }
    REP1(i,1,n) if ( SZ(rec[i])%2==1 ) rec[i].PB(m+2);
    REP1(i,1,n) for ( int j=0; j<SZ(rec[i]); j+=2 ) {
        in[rec[i][j]]++;
        out[rec[i][j+1]]++;
    }
    int now=0;
    REP1(i,1,m+2) {
        now+=in[i];
        now-=out[i];
        cnt[i]=now;
    }
    REP1(i,1,m+2) sc[i]=sc[i-1]+(cnt[i]>0);
    vector<int> sol;
    REP1(i,1,n) {
        if ( rec[i].empty() ) {
            sol.PB(i);
            continue;
        }
        int s=0;
        for ( int j=0; j<SZ(rec[i]); j+=2 ) {
            int st=rec[i][j];
            int ed=rec[i][j+1];
            s+=sc[ed-1]-sc[st-1];
        }
        if ( s==sc[m+2] ) sol.PB(i);
    }
    if ( sol.empty() ) puts("0");
    else {
        printf("%d\n",SZ(sol));
        REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
    }
    return 0;
}