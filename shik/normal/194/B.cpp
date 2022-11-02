// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int t;
    long long n;
    cin>>t;
    while ( t-- ) {
        cin>>n;
        cout<<4*n/__gcd(4*n,n+1)+1<<endl;
    }
    return 0;
}