// by shik
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Rec { int x1,y1,x2,y2; } r1,r2;
Rec u( Rec a, Rec b ) {
    Rec c;
    c.x2=max(min(a.x1,a.x2),min(b.x1,b.x2));
    c.x1=min(max(a.x1,a.x2),max(b.x1,b.x2));
    c.y2=max(min(a.y1,a.y2),min(b.y1,b.y2));
    c.y1=min(max(a.y1,a.y2),max(b.y1,b.y2));
    return c;
}
long long A( Rec a ) { 
    if ( a.x1<a.x2 ) return 0;
    if ( a.y1<a.y2 ) return 0; 
    return max(((long long)(a.x1-a.x2)+1)*((long long)(a.y1-a.y2)+1),0LL);
}
int main()
{
    int t,n,m,x1,y1,x2,y2,U,D,L,R; long long ans;
    scanf("%d",&t);
    while ( t-- ) {
        scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
        ans=(long long)(n)*m;
        n--; m--; x1--; x2--; y1--; y2--;
        U=n-max(x1,x2);
        D=min(x1,x2);
        R=m-max(y1,y2);
        L=min(y1,y2);
        r1=(Rec){x1+U,y1+R,x1-D,y1-L};
        r2=(Rec){x2+U,y2+R,x2-D,y2-L};
        ans-=A(r1)+A(r2);
        //printf("==%I64d\n",ans);
        ans+=A(u(r1,r2));
        //printf("(%d,%d,%d,%d):%I64d\n",u(r1,r2).x1,u(r1,r2).y1,u(r1,r2).x2,u(r1,r2).y2,A(u(r1,r2)));
        //printf("==%I64d\n",ans);
        cout<<ans<<endl;
    }
    return 0;
}