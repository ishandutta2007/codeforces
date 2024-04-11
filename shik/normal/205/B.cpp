// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int stk[100010],top;
int main()
{
    int n,x;
    long long ans=0;
    scanf("%d",&n);
    while ( n-- ) {
        scanf("%d",&x);
        while ( top>0 && x>=stk[top-1] ) {
            if ( top>1 ) ans+=min(x,stk[top-2])-stk[top-1];
            top--;
        }
        stk[top++]=x;
    }
    if ( top>0 ) ans+=stk[0]-stk[top-1];
    cout<<ans<<endl;
    return 0;
}