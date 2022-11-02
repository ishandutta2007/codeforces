// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 300010
int a[N],b[N],d[N],s[N],sn;
bool cp( int x, int y ) { return a[x]<a[y]; }
vector<int> e[N];
int main()
{
    int n,m,k=0;
    scanf("%d%d",&n,&m);
    for ( int i=0; i<m; i++ ) b[i]=i;
    while ( n-- ) {
        for ( int i=0; i<m; i++ ) scanf("%d",a+i);
        sort(b,b+m,cp);
        for ( int i=0; i<m; i++ ) if ( a[b[i]]!=-1 ) {
            if ( i==0 || a[b[i]]!=a[b[i-1]] ) k++;
            e[m+k].push_back(b[i]);
            e[b[i]].push_back(m+k+1);
        }
        k++;
    }
    for ( int i=0; i<m+k; i++ ) FOR(it,e[i]) d[*it]++;
    queue<int> q;
    for ( int i=0; i<m+k; i++ ) if ( d[i]==0 ) q.push(i);
    while ( !q.empty() ) {
        int p=q.front(); q.pop();
        if ( p<m ) s[sn++]=p;
        FOR(it,e[p]) if ( --d[*it]==0 ) q.push(*it);
    }
    if ( sn!=m ) puts("-1");
    else for ( int i=0; i<m; i++ ) printf("%d%c",s[i]+1,i==m-1?'\n':' ');
    return 0;
}