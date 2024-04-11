// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
#define N 100010
multiset<int> s;
int n,m;
int get( int x ) {
    int r=(x+*s.rbegin())%m;
    multiset<int>::iterator it=s.upper_bound(m-1-x);
    if ( it!=s.begin() ) r=max(r,x+*--it);
    return r;
}
priority_queue<PII> q;
int c1[N],sol[N],sn;
int main()
{
    scanf("%d%d",&n,&m);
    for ( int i=0; i<n; i++ ) {
        int x;
        scanf("%d",&x);
        c1[x]++;
    }
    for ( int i=0; i<n; i++ ) {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }
    for ( int i=0; i<m; i++ ) if ( c1[i] ) q.push(PII(get(i),i));
    while ( !q.empty() ) {
        int v=q.top().first;
        int x=q.top().second;
        q.pop();
        if ( get(x)!=v ) {
            q.push(PII(get(x),x));
            continue;
        }
        sol[sn++]=v;
        int y=v-x;
        if ( y<0 ) y+=m;
        s.erase(s.find(y));
        if ( --c1[x]>0 ) q.push(PII(get(x),x));
    }
    for ( int i=0; i<sn; i++ ) printf("%d%c",sol[i],i==sn-1?'\n':' ');
    return 0;
}