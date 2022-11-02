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

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int main() {
    double l,d,x=0,y=0;
    int dir=0,n;
    cin>>l>>d>>n;
    while ( d>=4*l ) d-=4*l;
    while ( n-- ) {
        double rem=d,t=0;
        while ( rem>0 ) {
            if ( dir==0 ) t=l-x;
            else if ( dir==1 ) t=l-y;
            else if ( dir==2 ) t=x;
            else if ( dir==3 ) t=y;
            if ( t>rem ) t=rem;
            rem-=t;
            x+=dx[dir]*t;
            y+=dy[dir]*t;
            if ( t==0 ) dir=(dir+1)%4;
        }
        printf("%.9f %.9f\n",x,y);
    }
    return 0;
}