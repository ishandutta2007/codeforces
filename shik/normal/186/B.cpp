// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
int n,t1,t2,k,a[N],b[N];
double get( int x, int y ) {
    double h=0;
    h+=x*t1;
    h*=(100-k)/100.0;
    h+=y*t2;
    return h;
}
int main()
{
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    for ( int i=0; i<n; i++ ) scanf("%d%d",a+i,b+i);
    pair<double,int> s[N];
    for ( int i=0; i<n; i++ ) s[i]=make_pair(-max(get(a[i],b[i]),get(b[i],a[i])),i+1);
    sort(s,s+n);
    for ( int i=0; i<n; i++ ) printf("%d %.2f\n",s[i].second,-s[i].first+1e-9);
    return 0;
}