// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int get_big( LL n ) {
    int big=0;
    while ( n ) {
        big=max(big,(int)(n%10));
        n/=10;
    }
    return big;
}
LL step[10][20][10],delta[10][20][10];
bool vis[10][20][10];
void go( int big, int len, int dig ) {
    if ( vis[big][len][dig] ) return;
    vis[big][len][dig]=1;
    LL &ss=step[big][len][dig];
    LL &dd=delta[big][len][dig];
    if ( len==0 ) {
        if ( big>dig ) {
            ss=1;
            dd=big;
        } else {
            ss=2;
            dd=dig+big;
        }
        return;
    }
    int last=dig;
    for ( int i=9; i>=0; i-- ) {
        go(max(big,i),len-1,last);
        LL &ns=step[max(big,i)][len-1][last];
        LL &nd=delta[max(big,i)][len-1][last];
        ss+=ns;
        dd+=nd;
        last-=nd%10;
        if ( last<0 ) last+=10;
    }
}
LL shik( LL &n ) {
    if ( n<1000 || n/100%100!=99 ) {
        int b=get_big(n);
        n-=b;
        return 1;
    }
    int d[20];
    LL m=n;
    for ( int i=0; i<20; i++ ) {
        d[i]=m%10;
        m/=10;
    }
    int len=1;
    while ( d[1+len]==9 ) len++;
    int big=0;
    for ( int i=1+len; i<20; i++ ) big=max(big,d[i]);
    if ( big==0 ) {
        big=9;
        len--;
    }
    go(big,len,d[0]);
    n-=delta[big][len][d[0]];
    return step[big][len][d[0]];
}
LL lasai( LL n ) {
    LL ans=0;
    while ( n ) {
        ans++;
        n-=get_big(n);
    }
    return ans;
}
int main()
{
    LL n,ans=0;
    cin>>n;
    //cout<<lasai(n)<<endl;
    while ( n ) {
        ans+=shik(n);
    }
    cout<<ans<<endl;
    return 0;
}