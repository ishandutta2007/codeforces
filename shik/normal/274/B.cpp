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
#define N 100010
#define INF 1234567890
vector<int> e[N];
int v[N];
LL pos[N],neg[N];
void go( int p, int f ) {
    FOR(it,e[p]) if ( *it!=f ) {
        go(*it,p);
        pos[p]=max(pos[p],pos[*it]);
        neg[p]=max(neg[p],neg[*it]);
    }
    int now=v[p]+pos[p]-neg[p];
    if ( now>0 ) neg[p]+=abs(now);
    else pos[p]+=abs(now);
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
    for ( int i=1; i<=n; i++ ) scanf("%d",v+i);
    go(1,0);
    cout<<pos[1]+neg[1]<<endl;
    return 0;
}