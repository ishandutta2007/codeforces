// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
pair<int,int> z[100010];
int main()
{
    int n,d,a,b,x,y;
    scanf("%d%d%d%d",&n,&d,&a,&b);
    for ( int i=0; i<n; i++ ) {
        scanf("%d%d",&x,&y);
        z[i].first=a*x+b*y;
        z[i].second=i+1;
    }
    sort(z,z+n);
    int m=0;
    while ( m<n && d>=z[m].first ) d-=z[m++].first;
    printf("%d\n",m);
    for ( int i=0; i<m; i++)  printf("%d%c",z[i].second,i==m-1?'\n':' ');
    return 0;
}