// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
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

#define N 310
int n,m,t,tp,tu,td,h[N][N];
int dpu[N],dpd[N];
int calc( int h1, int h2 ) {
    if ( h1<h2 ) return tu;
    else if ( h1>h2 ) return td;
    else return tp;
}
int main() {
    RI(n,m,t,tp,tu,td);
    REP1(i,1,n) REP1(j,1,m) RI(h[i][j]);
    int at=-1,ax1=0,ay1=0,ax2=0,ay2=0;
    auto upd=[&]( int tt, int x1, int y1, int x2, int y2 ) {
        if ( at!=-1 && abs(t-tt)>=abs(t-at) ) return;
        tie(at,ax1,ay1,ax2,ay2)=make_tuple(tt,x1,y1,x2,y2);
    };
    REP1(i,1,n) {
        memset(dpu,0,sizeof(dpu));
        memset(dpd,0,sizeof(dpd));
        REP1(j,i+1,n) {
            REP1(k,1,m) dpu[k]+=calc(h[j][k],h[j-1][k]);
            REP1(k,1,m) dpd[k]+=calc(h[j-1][k],h[j][k]);
            if ( j==i+1 ) continue;
            int now=0;
            set<PII> s;
            PII todo;
            REP1(k,1,m) {
                if ( k>1 ) {
                    now+=calc(h[i][k-1],h[i][k]);
                    now+=calc(h[j][k],h[j][k-1]);
                }
                int tr=now+dpd[k];
                auto it=s.lower_bound(MP(tr-t,0));
                if ( it!=s.end() ) upd(tr-it->first,i,it->second,j,k);
                if ( it!=s.begin() ) {
                    it--;
                    upd(tr-it->first,i,it->second,j,k);
                }
                if ( k>=2 ) s.insert(todo);
                todo=MP(now-dpu[k],k);
            }
        }
    }
    printf("%d %d %d %d\n",ax1,ay1,ax2,ay2);
    return 0;
}