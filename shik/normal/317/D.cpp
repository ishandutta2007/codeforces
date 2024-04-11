// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int sg[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
bool vis[100000];
int main()
{
    int n,c[30]={};
    scanf("%d",&n);
    int sn=0;
    while ( (sn+1)*(sn+1)<=n ) sn++;
    c[1]=n-sn+1;
    for ( int i=2; i<=sn; i++ ) if ( !vis[i] ) {
        int t=0;
        LL p=1;
        while ( p<=n ) {
            if ( p<=sn ) vis[p]=1;
            else c[1]--;
            t++;
            p*=i;
        }
        c[t-1]++;
    }
    int s=0;
    for ( int i=1; i<30; i++ ) if ( c[i]%2==1 ) s^=sg[i];
    if ( s ) puts("Vasya");
    else puts("Petya");
    return 0;
}