// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
vector<int> e[N];
char sol[N];
int vis[N],cc[N],nc,sz[N],bl[N];
int go2( int p, int f ) {
    cc[nc++]=p;
    sz[p]=1;
    bl[p]=0;
    FOR(it,e[p]) if ( *it!=f && !vis[*it] ) {
        int now=go2(*it,p);
        sz[p]+=now;
        bl[p]=max(bl[p],now);
    }
    return sz[p];
}
int get_root( int p ) {
    nc=0;
    go2(p,0);
    int r=-1,sml=N;
    for ( int i=0; i<nc; i++ ) {
        int q=cc[i];
        bl[q]=max(bl[q],nc-sz[q]);
        if ( bl[q]<sml ) {
            sml=bl[q];
            r=q;
        }
    }
    return r;
}
void go( int p, int lv ) {
    p=get_root(p);
    sol[p]='A'+lv;
    vis[p]=1;
    FOR(it,e[p]) if ( !vis[*it] ) go(*it,lv+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=1; i<n; i++ ) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    go(1,0);
    for ( int i=1; i<=n; i++ ) printf("%c%c",sol[i],i==n?'\n':' ');
    return 0;
}