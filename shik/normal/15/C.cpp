// by shik
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long Q( long long x, int b ) {
    if ( b==0 ) {
        if ( (x+1)/2%2==1 ) return 1;
        else return 0;
    } 
    x%=(1LL<<(b+1));
    if ( x<(1LL<<b) ) return 0;
    x-=(1LL<<b);
    if ( x%2==0 ) return 1LL<<b;
    else return 0; 
} 
int main()
{
    int n,i; long long sg=0,now,m,x,a,b;
    //printf("==%I64d,%I64d\n",Q(0,0),Q(3,0));
    scanf("%d",&n);
    while ( n-- ) {
        //scanf("%I64d%I64d",&x,&m);
        cin>>x>>m;
        a=x; b=x+m-1;
        for ( i=now=0; i<60; i++ ) sg^=Q(a-1,i)^Q(b,i);
    }
    if ( sg>0 ) puts("tolik");
    else puts("bolik"); 
    return 0;
}