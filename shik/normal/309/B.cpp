// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline int bit( int x, int i ) { return (x>>i)&1; }
#define N 1000010
int len[N],to[20][N];
string s[N];
char buf[5145140];
int main()
{
    int n,r,c;
    scanf("%d%d%d",&n,&r,&c);
    for ( int i=1; i<=n; i++ ) {
        scanf("%s",buf);
        s[i]=buf;
        len[i]=s[i].size();
    }
    c++;
    for ( int i=1; i<=n; i++ ) len[i]++;
    int now=0;
    for ( int i=n,j=n; i>=1; i-- ) {
        now+=len[i];
        while ( now>c ) now-=len[j--];
        to[0][i]=j;
    }
    to[0][n+1]=n;
    for ( int i=1; i<20; i++ ) for ( int j=1; j<=n+1; j++ ) to[i][j]=to[i-1][to[i-1][j]+1];
    int big=0,pos=1;
    for ( int i=1; i<=n; i++ ) {
        int p=i;
        for ( int j=0; j<20; j++ ) if ( bit(r,j) ) p=to[j][p]+1;
        if ( p-i>big ) {
            big=p-i;
            pos=i;
        }
    }
    for ( int i=0; i<r; i++ ) {
        int npos=to[0][pos];
        for ( int j=pos; j<=npos; j++ ) printf("%s%c",s[j].c_str(),j==npos?'\n':' ');
        pos=npos+1;
    }
    return 0;
}