#include <iostream>
using namespace std;
typedef long long LL;

LL t,n,m;
int main() {
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        LL A = (n*m+1)/2, B=(n*m)/2;
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        A += (LL)(x2-x1+1)*(y2-y1+1);
        LL da=(LL)(x2-x1+1)*(y2-y1+1)/2;
        LL db=(LL)(x2-x1+1)*(y2-y1+1)/2;
        if((LL)(x2-x1+1)*(y2-y1+1) % 2 == 1){
            if((x1+y1)%2==1) db++; else da++;
        }
        A -= da; B -= db;

        int x3,y3,x4,y4; scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
        B += (LL)(x4-x3+1)*(y4-y3+1);
        da=(LL)(x4-x3+1)*(y4-y3+1)/2;
        db=(LL)(x4-x3+1)*(y4-y3+1)/2;
        if((LL)(x4-x3+1)*(y4-y3+1) % 2 == 1){
            if((x3+y3)%2==1) db++; else da++;
        }
        A -= da; B -= db;

        int x5,y5,x6,y6; x5=max(x1,x3); x6=min(x2,x4); y5=max(y1,y3); y6=min(y2,y4);
        if(x5<=x6 && y5<=y6) {
            A -= (LL)(x6-x5+1)*(y6-y5+1);
            da=(LL)(x6-x5+1)*(y6-y5+1)/2;
            db=(LL)(x6-x5+1)*(y6-y5+1)/2;
            if((LL)(x6-x5+1)*(y6-y5+1) % 2 == 1){
                if((x5+y5)%2==1) db++; else da++;
            }
            A += da; B += db;
        }
        printf("%lld %lld\n", A,B);
    }
}