// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10000010
using namespace std;
int fa[N];
int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
void Union( int a, int b ) {
    if ( rand()%2 ) swap(a,b);
    fa[Find(a)]=Find(b);    
}
bool chk( int a, int b ) {
    if ( fa[a] && fa[b] && Find(a)!=Find(b) ) {
        Union(a,b);
        return 1;
    }
    return 0;
}
int main()
{
    int n,x,ans; long long i,j,a,b,c;
    scanf("%d",&n); ans=n;
    while ( n-- ) {
        scanf("%d",&x);
        fa[x]=x;
    }
    for ( i=1; i<N; i++ )
        for ( j=i+1; (a=2*i*j)<N && (b=j*j-i*i)<N; j++ ) {
            if ( (i+j)%2==0 ) continue;
            if ( __gcd(i,j)!=1 ) continue;
            c=j*j+i*i;
            if ( chk(a,b) ) ans--;
            if ( c<N ) {
                if ( chk(a,c) ) ans--;
                if ( chk(b,c) ) ans--;
            }
        }
    printf("%d\n",ans);
    return 0;
}