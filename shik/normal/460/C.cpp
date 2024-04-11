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
int n,m,w,h[N];

bool chk( int mid ) {
    static int in[N],out[2*N];
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    int rem=m,now=0;
    REP1(i,1,n) {
        now+=in[i];
        while ( h[i]+now<mid ) {
            if ( rem==0 ) return 0;
            rem--;
            now++;
            out[i+w-1]++;
        }
        now-=out[i];
    }
    return 1;
}

int main() {
    RI(n,m,w);
    REP1(i,1,n) RI(h[i]);
    int l=1,r=1e9+m;
    while ( l!=r ) {
        int mid=(l+r+1)/2;
        if ( chk(mid) ) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}