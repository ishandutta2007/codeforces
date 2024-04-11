// by shik
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,h,a1=0,a2=0,i,app[1010]={};
    scanf("%d",&n);
    while ( n-- ) {
        scanf("%d",&h);
        app[h]++;
    }
    for ( i=1; i<=1000; i++ ) {
        a1=max(app[i],a1);
        if ( app[i]>0 ) a2++;   
    }
    printf("%d %d\n",a1,a2);
    return 0;
}