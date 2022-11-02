// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> e[N];
int h,t;
int jiao( int a, int b ) {
    int ans=0,da=SZ(e[a]),db=SZ(e[b]);
    for ( int i=0,j=0; i<da; i++ ) {
        while ( j<db && e[b][j]<e[a][i] ) j++;
        if ( j<db && e[a][i]==e[b][j] ) ans++;
    }
    return ans;
}
void solve( int a, int b ) {
    puts("YES");
    printf("%d %d\n",a,b);
    vector<int> sa,sb,sc;
    int da=SZ(e[a]),db=SZ(e[b]);
    for ( int i=0,j=0; i<da || j<db; ) {
        if ( i<da && e[a][i]==b ) i++;
        else if ( j<db && e[b][j]==a ) j++;
        else if ( i==da ) sb.push_back(e[b][j++]);
        else if ( j==db ) sa.push_back(e[a][i++]);
        else if ( e[a][i]<e[b][j] ) sa.push_back(e[a][i++]);
        else if ( e[a][i]>e[b][j] ) sb.push_back(e[b][j++]);
        else {
            sc.push_back(e[a][i]);
            i++; j++;
        }
    }
    while ( SZ(sa)<h ) {
        sa.push_back(sc.back());
        sc.pop_back();
    }
    while ( SZ(sb)<t ) {
        sb.push_back(sc.back());
        sc.pop_back();
    }
    for ( int i=0; i<h; i++ ) printf("%d%c",sa[i],i==h-1?'\n':' ');
    for ( int i=0; i<t; i++ ) printf("%d%c",sb[i],i==t-1?'\n':' ');
}
bool chk( int a, int b ) {
    int da=SZ(e[a]),db=SZ(e[b]);
    if ( da<h+1 ) return 0;
    if ( db<t+1 ) return 0;
    if ( da+db>514 ) {
        solve(a,b);
        return 1;
    }
    int dc=jiao(a,b);
    if ( da+db-dc>=h+t+2 ) {
        solve(a,b);
        return 1;
    }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d%d%d",&n,&m,&h,&t);
    while ( m-- ) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    };
    for ( int i=1; i<=n; i++ ) sort(e[i].begin(),e[i].end());
    for ( int i=1; i<=n; i++ ) FOR(it,e[i]) if ( chk(i,*it) ) return 0;
    puts("NO");
    return 0;
}