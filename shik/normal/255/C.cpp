// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 4010
#define M 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int s[N],p[N],q[M],c[M];
int main()
{
    int n,ans=1;
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",s+i);
    for ( int i=1; i<=n; i++ ) c[s[i]]++;
    for ( int i=0; i<M; i++ ) ans=max(ans,c[i]);
    memset(c,0,sizeof(c));
    for ( int i=1; i<=n; i++ ) {
        p[n+1]=n+1;
        for ( int j=n; j>=i; j-- ) {
            p[j]=p[j+1];
            if ( s[j]==s[i] ) p[j]=j;
        }
        for ( int j=i+1; j<=n; j++ ) if ( s[j]!=s[i] && q[s[j]]!=p[j] ) {
            q[s[j]]=p[j];
            if ( p[j]<=n ) c[s[j]]+=2;
            else c[s[j]]++;
        }
        for ( int j=i+1; j<=n; j++ ) if ( c[s[j]]>0 ) {
            ans=max(ans,c[s[j]]+1);
            c[s[j]]=q[s[j]]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}