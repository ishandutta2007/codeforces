// by shik
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct S { int x,a; } s[1000];
bool operator <( const S &a, const S &b ) { return a.x<b.x; };
int main()
{
    int n,t,i,ans=2;
    scanf("%d%d",&n,&t);
    for ( i=0; i<n; i++ ) scanf("%d%d",&s[i].x,&s[i].a);
    sort(s,s+n);
    for ( i=1; i<n; i++ ) {
        if ( 2*s[i].x-2*s[i-1].x-s[i].a-s[i-1].a > 2*t ) ans+=2;
        else if ( 2*s[i].x-2*s[i-1].x-s[i].a-s[i-1].a == 2*t ) ans++;
    }
    printf("%d\n",ans);
    return 0;
}