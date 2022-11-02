// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int n,m,c[N];
struct cp {
    bool operator()( int a, int b ) {
        if ( c[a]!=c[b] ) return c[a]>c[b];
        if ( abs(m+1-2*a)!=abs(m+1-2*b) ) return abs(m+1-2*a)>abs(m+1-2*b);
        return a>b;
    }
};
int main()
{
    priority_queue<int,vector<int>,cp> q;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=m; i++ ) q.push(i);
    while ( n-- ) {
        int x=q.top(); q.pop();
        printf("%d\n",x);
        c[x]++;
        q.push(x);
    }
    return 0;
}