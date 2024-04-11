// by shik
#include <cstdio>
#define N 100010
int n,vis[N],sol[N];
int main() {
    scanf("%d",&n);
    if ( n%2==1 ) puts("-1");
    else {
        sol[n]=0;
        for ( int i=n; i>0; i-- ) {
            vis[sol[i]]=1;
            sol[i-1]=sol[i]/2 + (vis[sol[i]^1] ? 0 : n/2);
        }
        for ( int i=0; i<=n; i++ ) printf("%d%c",sol[i],i==n?'\n':' ');
    }
    return 0;
}