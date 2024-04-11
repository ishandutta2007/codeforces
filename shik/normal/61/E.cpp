// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1000010
struct BIT {
    int dat[N];
    void ins( int x ) { for ( int i=x; i<N; i+=i&-i ) dat[i]++; }
    int ask( int x ) { int r=0; for ( int i=x; i; i-=i&-i ) r+=dat[i]; return r; }
} b1,b2;
int n,a[N],b[N],x[N],y[N];
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    memcpy(b,a,n*sizeof(int));
    sort(b,b+n);
    for ( int i=0; i<n; i++ ) a[i]=lower_bound(b,b+n,a[i])-b+1;
    for ( int i=n-1; i>=0; i-- ) {
        x[i]=b1.ask(a[i]-1);
        b1.ins(a[i]);
    }
    for ( int i=0; i<n; i++ ) {
        y[i]=i-b2.ask(a[i]);
        b2.ins(a[i]);
    }
    long long ans=0;
    for ( int i=0; i<n; i++ ) ans+=1LL*x[i]*y[i];
    cout<<ans<<endl;
    return 0;
}