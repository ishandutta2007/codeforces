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
#define N 80010
LL sz[N],ac[N];
vector<int> e[N];
LL go( int p, int f ) {
    sz[p]=1;
    ac[p]=0;
    LL s=0;
    FOR(it,e[p]) if ( *it!=f ) {
        sz[p]+=go(*it,p);
        ac[p]+=sz[*it];
        s+=sz[*it]*sz[*it];
    }
    ac[p]+=(ac[p]*ac[p]-s)/2;
    return sz[p];
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
    unsigned long long ans=1LL*n*(n-1)/2;
    ans=ans*ans;
    for ( int i=1; i<=n; i++ ) ans-=ac[i]*ac[i];
    for ( int i=1; i<=n; i++ ) ans-=(unsigned long long)(n-sz[i])*sz[i]*ac[i]*2;
    cout<<ans<<endl;
    return 0;
}