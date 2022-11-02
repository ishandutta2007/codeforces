// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
void get( int n, int a[N], int &x, int &y ) {
    x=1; y=0;
    for ( int i=1; i<n; i++ ) if ( a[i]!=a[i-1] ) x++;
    for ( int i=0; i<n; i++ ) if ( a[i]==1 && (i==0||a[i-1]==0) ) y++;
}
int n,m,a[N],b[N],c[2*N],s[2*N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    scanf("%d",&m);
    for ( int i=0; i<m; i++ ) scanf("%d",b+i);
    int xa,ya,xb,yb,pa=0,pb=0,pc=0;
    get(n,a,xa,ya);
    get(m,b,xb,yb);
    if ( xa>xb || (xa==xb && ya>yb) || (xa==xb && ya==yb && a[0]==0) ) {
        c[pc]=a[pa];
        s[pc]=pa+1;
        pc++; pa++;
    } else {
        c[pc]=b[pb];
        s[pc]=n+pb+1;
        pc++; pb++;
    }
    while ( pa<n || pb<m ) {
        if ( pc>0 && pa<n && a[pa]==c[pc-1] ) {
            c[pc]=a[pa];
            s[pc]=pa+1;
            pc++; pa++;
        } else if ( pc>0 && pb<m && b[pb]==c[pc-1] ) {
            c[pc]=b[pb];
            s[pc]=n+pb+1;
            pc++; pb++;
        } else if ( pa<n ) {
            c[pc]=a[pa];
            s[pc]=pa+1;
            pc++; pa++;
        } else if ( pb<m ) {
            c[pc]=b[pb];
            s[pc]=n+pb+1;
            pc++; pb++;
        }
    }
    for ( int i=0; i<pc; i++ ) printf("%d%c",s[i],i==pc-1?'\n':' ');
    while ( pc>0 && c[pc-1]==0 ) pc--;
    int sn=0;
    while ( pc>0 ) {
        s[sn++]=pc--;
        while ( pc>0 && c[pc-1]==c[pc] ) pc--;
    }
    sort(s,s+sn);
    printf("%d\n",sn);
    for ( int i=0; i<sn; i++ ) printf("%d%c",s[i],i==sn-1?'\n':' ');
    return 0;
}