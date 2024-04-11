// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for (auto it=begin(c); it!=end(c); it++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
/// }}}

int rec[4010],shik[4010];
int main() {
    int x,k;
    RI(x,k);
    REP(i,k) {
        int op,n1,n2;
        RI(op);
        if ( op==1 ) {
            RI(n2,n1);
            rec[n2]=2;
            rec[n1]=1;
        } else {
            RI(n2);
            rec[n2]=2;
            rec[n2+1]=2;
        }
    }
    REP1(i,1,x-1) {
        if ( rec[i] ) shik[i]=rec[i];
        else if ( shik[i-1]==2 ) shik[i]=1;
        else shik[i]=2;
    }
    int ans1=count(shik,shik+x,2)-k;
    int ans2=x-1-count(rec,rec+x,1)-k;
    printf("%d %d\n",ans1,ans2);
    return 0;
}