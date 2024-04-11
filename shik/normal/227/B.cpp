// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int p[100010];
int main()
{
    int n;
    cin>>n;
    for ( int i=1; i<=n; i++ ) {
        int x;
        cin>>x;
        p[x]=i;
    }
    int m;
    long long a=0,b=0;
    cin>>m;
    while ( m-- ) {
        int x;
        cin>>x;
        a+=p[x];
        b+=n-p[x]+1;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}