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
int n,d,a[N],b[N],c[N];
LL x;
LL getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int nb,ia[N];
int main() {
    cin>>n>>d>>x;
    initAB();
    REP(i,n) if ( b[i] ) b[nb++]=i;
    REP(i,n) ia[a[i]]=i;
    int rem=n;
    memset(c,-1,sizeof(c));
    for ( int i=n; i>=1; i-- ) {
        int ai=ia[i];
        REP(j,nb) {
            int p=ai+b[j];
            if ( p>=n ) break;
            if ( c[p]==-1 ) c[p]=i,rem--;
        }
        if ( 1LL*rem*nb<10000000 ) break;
    }
    REP(i,n) if ( c[i]==-1 ) {
        int mx=0;
        REP(j,nb) {
            int p=i-b[j];
            if ( p<0 ) break;
            if ( a[p]>mx ) mx=a[p];
        }
        c[i]=mx;
    }
    REP(i,n) printf("%d\n",c[i]);
    return 0;
}