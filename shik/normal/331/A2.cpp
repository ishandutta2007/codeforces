// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;

#define N 300010
int n;
LL a[N],s[N];
int main()
{
    cin>>n;
    for ( int i=1; i<=n; i++ ) cin>>a[i];
    for ( int i=1; i<=n; i++ ) s[i]=s[i-1]+max(a[i],0LL);
    map<int,int> mp;
    LL ans=(LL)-1e15;
    int al=-1,ar=-1;
    for ( int i=1; i<=n; i++ ) {
        if ( mp.count(a[i]) ) {
            int j=mp[a[i]];
            LL now=a[i]+a[j]+s[i-1]-s[j];
            if ( now>ans ) {
                ans=now;
                al=j;
                ar=i;
            }
            if ( a[i]-s[i]>a[j]-s[j] ) mp[a[i]]=i;
        } else {
            mp[a[i]]=i;
        }
    }
    vector<int> sol;
    for ( int i=1; i<al; i++ ) sol.push_back(i);
    for ( int i=al+1; i<ar; i++ ) if ( a[i]<0 ) sol.push_back(i);
    for ( int i=ar+1; i<=n; i++ ) sol.push_back(i);
    cout<<ans<<" "<<SZ(sol)<<endl;
    for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
    return 0;
}