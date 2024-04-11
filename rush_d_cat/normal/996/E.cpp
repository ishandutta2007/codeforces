#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, ans[100000+10];

struct Nod {
    LL x, y, id;
} p[100000+10];
bool cmp(Nod A, Nod B) {
    return A.x*A.x+A.y*A.y < B.x*B.x+B.y*B.y;
}
int main(){
    scanf("%d",&n);

    LL sx=0,sy=0;
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y); 
        p[i].id = i;
    }
    while(true) {
        sx=0,sy=0;
        random_shuffle(p+1,p+1+n);
        for(int i=1;i<=n;i++) {
            LL d1 = (p[i].x+sx)*(p[i].x+sx) + (p[i].y+sy)*(p[i].y+sy);
            LL d2 = (p[i].x-sx)*(p[i].x-sx) + (p[i].y-sy)*(p[i].y-sy);
            if(d1<d2) {
                ans[p[i].id]=1;
                sx += p[i].x, sy += p[i].y;
            } else {
                sx -= p[i].x, sy -= p[i].y;
                ans[p[i].id]=-1;
            }
        }
        if (sx*sx+sy*sy>1500000LL*1500000LL) continue;
        for(int i=1;i<=n;i++) {
            printf("%d\n", ans[i]);
        }
        exit(0);
    }
}