// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,t[100010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",t+i);
    int z=count(t,t+n,0);
    int lp=0,ln=0,rp=0,rn=0,sml=n;
    for ( int i=0; i<n; i++ )
        if ( t[i]>0 ) rp++;
        else if ( t[i]<0 ) rn++;
    for ( int i=0; i<n-1; i++ ) {
        if ( t[i]>0 ) rp--,lp++;
        else if ( t[i]<0 ) rn--,ln++;
        sml=min(sml,lp+rn);
    }
    printf("%d\n",sml+z);
    return 0;
}