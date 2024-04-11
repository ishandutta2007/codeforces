// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define MOD 1000000007
int pw( int a, int b ) {
    if ( b==0 ) return 1;
    LL t=pw(a,b/2);
    if ( b%2==0 ) return t*t%MOD;
    else return t*t%MOD*a%MOD;
}
int n,k,ans,per[8];
bool check() {
    bool ok[8]={};
    for ( int i=0; i<k; i++ ) if ( per[i]==0 ) ok[i]=1;
    bool flg=1;
    while ( flg ) {
        flg=0;
        for ( int i=0; i<k; i++ ) if ( !ok[i] && ok[per[i]] ) ok[i]=flg=1;
    }
    for ( int i=0; i<k; i++ ) if ( !ok[i] ) return 0;
    return 1;
}
void go( int p ) {
    if ( p==k ) {
        if ( check() ) ans++;
        return;
    }
    for ( int i=0; i<k; i++ ) {
        per[p]=i;
        go(p+1);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    go(0);
    printf("%d\n",(int)(1LL*ans*pw(n-k,n-k)%MOD));
    return 0;
}