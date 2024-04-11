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
int main()
{
    LL n;
    cin>>n;
    vector<LL> sol;
    for ( LL i=1; i-1<=n; i*=2 ) {
        LL l=1,r=1;
        auto f = [&]( LL x ) { return (i-1+(x-1)/2)*x; };
        while ( f(r)<n ) r*=2;
        while ( l!=r ) {
            LL m=(l+r)/2;
            if ( f(m)<n ) l=m+1;
            else r=m;
        }
        if ( l%2==1 && f(l)==n ) sol.push_back(i*l);
    }
    if ( sol.empty() ) puts("-1");
    else {
        FOR(it,sol) cout<<*it<<endl;
    }
    return 0;
}