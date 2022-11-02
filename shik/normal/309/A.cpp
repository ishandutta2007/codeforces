// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define N 1000010
LL a[2*N];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    LL l,t;
    cin>>n>>l>>t;
    for ( int i=1; i<=n; i++ ) cin>>a[i];
    double ans=0;
    ans+=(double)n*(n-1)*(t/l);
    t%=l;
    for ( int i=1; i<=n; i++ ) a[i+n]=a[i]+l;
    for ( int i=1,j=1,k=1; i<=n; i++ ) {
        while ( j+1<i+n && a[j+1]-a[i]<=2*t ) j++;
        while ( k+1<i+n && a[k+1]-a[i]+l<=2*t ) k++;
        ans+=0.25*(j-i);
        if ( k>i ) ans+=0.25*(k-i);
    }
    for ( int i=2*n,j=2*n,k=2*n; i>n; i-- ) {
        while ( j-1>i-n && a[i]-a[j-1]<=2*t ) j--;
        while ( k-1>i-n && a[i]-a[k-1]+l<=2*t ) k--;
        ans+=0.25*(i-j);
        if ( i>k ) ans+=0.25*(i-k);
    }
    ans/=2;
    cout.precision(14);
    cout<<ans<<endl;
    return 0;
}