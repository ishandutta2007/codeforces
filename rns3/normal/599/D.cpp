#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

struct dat{
    ll x,y;
    dat(ll x=0,ll y=0):x(x),y(y){}
}p[1000000];

bool operator < (dat A,dat B) {
    if(A.x!=B.x) return A.x<B.x;
    return A.y<B.y;
}

bool operator == (dat A,dat B) {
    if(A.x==B.x&&A.y==B.y) return 1;
    return 0;
}

int main() {
    ///freopen("1.in","r",stdin);
    ll x;
    scanf("%I64d\n",&x);
    int cnt = 0;
    for(ll i=1;i<=2e6;i++) {
        if(6 * x %  (i * (i+1)) == 0) {
            ll y = 6 * x /i/(i+1);
            if((2 * i - 2) > y) continue;
            if((y - 2 * i + 2 ) % 3) continue;
            ll z = (y - 2 * i + 2 ) /3;
            ll j = i + z - 1;
            p[cnt++] = dat(i,j);
            p[cnt++] = dat(j,i);
        }
    }
    sort(p,p+cnt);
    cnt = unique(p,p+cnt) - p;
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++) {
        printf("%I64d %I64d\n",p[i].x,p[i].y);
    }
}