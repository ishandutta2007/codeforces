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
double ans;
void go( int p, int f, int lv ) {
    ans+=1.0/lv;
    FOR(it,e[p]) if ( *it!=f ) go(*it,p,lv+1);
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
    go(1,0,1);
    printf("%.9f\n",ans);
    return 0;
}