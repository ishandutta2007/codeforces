// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define MP make_pair
typedef pair<int,int> PII;
typedef vector<PII> VII;
map<int,VII> mx,my;
map<int,int> lx,ly;
int get_len( VII &v ) {
    sort(v.begin(),v.end());
    int ans=0,pre=0;
    FOR(it,v) {
        int l=it->first,r=it->second;
        if ( r<=pre ) continue;
        ans+=r-max(pre,l);
        pre=r;
    }
    return ans;
}
int solve( VII &v, int l ) {
    int pre=0;
    FOR(it,v) {
        if ( it->second <= pre ) continue;
        if ( it->first <= pre ) {
            pre=it->second;
            continue;
        }
        if ( it->first-pre < l ) {
            l-=it->first-pre;
            pre=it->second;
        } else {
            return pre+l;
        }
    }
    return pre+l;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while ( k-- ) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if ( x1>x2 ) swap(x1,x2);
        if ( y1>y2 ) swap(y1,y2);
        if ( x1==x2 ) mx[x1].push_back(MP(y1,y2));
        else if ( y1==y2 ) my[y1].push_back(MP(x1,x2));
        else puts("QQ");
    }
    for ( int i=1; i<n; i++ ) if ( !mx.count(i) ) { mx[i].clear(); break; }
    for ( int i=1; i<m; i++ ) if ( !my.count(i) ) { my[i].clear(); break; }
    FOR(it,mx) lx[it->first]=get_len(it->second);
    FOR(it,my) ly[it->first]=get_len(it->second);
    int sg=0;
    if ( (n-1-SZ(lx))%2!=0 ) sg^=m;
    if ( (m-1-SZ(ly))%2!=0 ) sg^=n;
    FOR(it,lx) sg^=m-it->second;
    FOR(it,ly) sg^=n-it->second;
    if ( sg==0 ) puts("SECOND");
    else {
        puts("FIRST");
        FOR(it,lx) {
            int r=m-it->second;
            if ( (sg^r)<r ) {
                printf("%d %d %d %d\n",it->first,0,it->first,solve(mx[it->first],r-(sg^r)));
                return 0;
            }
        }
        FOR(it,ly) {
            int r=n-it->second;
            if ( (sg^r)<r ) {
                printf("%d %d %d %d\n",0,it->first,solve(my[it->first],r-(sg^r)),it->first);
                return 0;
            }
        }
    }
    return 0;
}