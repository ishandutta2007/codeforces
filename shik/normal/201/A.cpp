// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) (int)((x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    if ( x==1 ) puts("1");
    else if ( x==3 ) puts("5");
    else if ( x<=5 ) puts("3");
    else {
        for ( int i=5; ; i+=2 ) {
            int l=(i-1)/2,t=0;
            if ( l%2==0 ) {
                t+=l*l/2*4;
                t+=2*l/2*2;
                t+=1;
            } else {
                int t1=0,t2=0;
                t1+=l*l/2*4;
                t1+=(l+1)*2;
                t2+=(l*l/2+1)*4;
                t2+=(l-1)*2+1;
                t=max(t1,t2);
            }
            if ( t>=x ) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}