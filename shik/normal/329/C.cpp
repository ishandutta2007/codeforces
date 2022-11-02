// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
#define N 100010
set<PII> bye;
int per[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=0; i<m; i++ ) {
        int a,b;
        scanf("%d%d",&a,&b);
        bye.insert(PII(a,b));
        bye.insert(PII(b,a));
    }
    int cut=10000;
    for ( int i=0; i<n; i++ ) per[i]=i+1;
    while ( cut-- ) {
        random_shuffle(per,per+n);
        per[n]=per[0];
        int cnt=0;
        for ( int i=0; i<n; i++ ) if ( !bye.count(PII(per[i],per[i+1])) ) cnt++;
        if ( cnt>=m ) {
            for ( int i=0; m>0; i++ ) if ( !bye.count(PII(per[i],per[i+1])) ) {
                printf("%d %d\n",per[i],per[i+1]);
                m--;
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}