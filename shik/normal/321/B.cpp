// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 200
int atk[N],def[N],t[N],s[N],n,n1,n2,m;
int main()
{
    scanf("%d%d",&n,&m);
    for ( int i=0; i<n; i++ ) {
        char op[10];
        scanf("%s%d",op,t+i);
        if ( op[0]=='A' ) atk[n1++]=t[i];
        else def[n2++]=++t[i];
    }
    for ( int i=0; i<m; i++ ) scanf("%d",s+i);
    sort(atk,atk+n1);
    sort(def,def+n2);
    sort(s,s+m);
    int ans=0;
    for ( int i=1; i<=n1&&i<=m; i++ ) {
        int now=0;
        for ( int j=0; j<i; j++ ) if ( s[m-i+j]>=atk[j] ) now+=s[m-i+j]-atk[j];
        ans=max(ans,now);
    }
    bool ok=1;
    int now=0;
    bool used[N]={};
    for ( int i=0; i<n2; i++ ) {
        bool ya=0;
        for ( int j=0; j<m; j++ ) if ( !used[j] && s[j]>=def[i] ) {
            used[j]=ya=1;
            break;
        }
        if ( !ya ) {
            ok=0;
            break;
        }
    }
    for ( int i=0; i<n1; i++ ) {
        bool ya=0;
        for ( int j=0; j<m; j++ ) if ( !used[j] && s[j]>=atk[i] ) {
            used[j]=ya=1;
            now+=s[j]-atk[i];
            break;
        }
        if ( !ya ) {
            ok=0;
            break;
        }
    }
    for ( int i=0; i<m; i++ ) if ( !used[i] ) now+=s[i];
    if ( ok ) ans=max(ans,now);
    printf("%d\n",ans);
    return 0;
}