#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,x;
struct Nod {
    int d,h;
    bool operator<(const Nod&o)const{
        return d-h > o.d-o.h;
    }
} nod[N];

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d%d",&nod[i].d,&nod[i].h);
        sort(nod+1,nod+1+n);
        int mx=0; for(int i=1;i<=n;i++) mx=max(mx,nod[i].d);

        int need=x-mx;
        if(need<=0) {printf("1\n");continue;}
        else {
            if(nod[1].d <= nod[1].h) {printf("-1\n");continue;}
            int t1=(need+nod[1].d - nod[1].h-1)/(nod[1].d - nod[1].h);
            int now=x-t1*(nod[1].d-nod[1].h);
            if(now>0) t1++;
            printf("%d\n", t1);
        }
    }
}