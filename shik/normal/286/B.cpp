// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 2000010
int x[N];
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) x[i]=i;
    int off=0;
    for ( int i=2; i<=n; i++ ) {
        int last=n-(n%i)+1;
        if ( last>n ) last-=i;
        x[n+off+1]=x[last+off];
        for ( int j=last+off; j-i>0; j-=i ) x[j]=x[j-i];
        off++;
    }
    for ( int i=1; i<=n; i++ ) printf("%d%c",x[i+off],i==n?'\n':' ');
    return 0;
}