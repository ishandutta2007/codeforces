// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int n,a[N],l[N],r[N],die[N];
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<=n; i++ ) r[i]=i+1;
    for ( int i=1; i<=n+1; i++ ) l[i]=i-1;
    vector<int> v;
    for ( int i=2; i<=n; i++ ) if ( a[i-1]>a[i] ) v.push_back(i);
    int ans=0;
    while ( !v.empty() ) {
        ans++;
        vector<int> nv;
        for ( auto &i : v ) {
            die[i]=1;
            r[l[i]]=r[i];
            l[r[i]]=l[i];
            if ( l[i]>0 && r[i]<=n && a[l[i]]>a[r[i]] ) nv.push_back(r[i]);
        }
        v.clear();
        for ( auto &i : nv ) if ( !die[i] ) v.push_back(i);
    }
    printf("%d\n",ans);
    return 0;
}