#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const LL INF = 1e9+7;
const int N = 100000 + 10;
int n;
struct Point {
    LL x, y;
    void read() {
        scanf("%lld %lld",&x,&y);
    }
    bool operator < (const Point & b) const {
        return x < b.x;
    }
} p[N];
LL x[N],y[N];
LL preMax[N],preMin[N],sufMin[N],sufMax[N];

bool ok(LL M) {
    LL t = sqrt(M); if(t*t>M) t++;
    for(int i=1;i<=n;i++) {
        LL ymin = preMin[i-1];
        LL ymax = preMax[i-1];
        int pos;
        if (x[i] < 0)
            pos = upper_bound(x+1,x+1+n,min(-x[i],x[i]+t)) - x;
        else 
            pos = upper_bound(x+1,x+1+n,x[i]) - x;

        ymax = max(ymax, sufMax[pos]);
        ymin = min(ymin, sufMin[pos]);

        if ((ymax-ymin)*(ymax - ymin)<=M && (ymax*ymax+x[i]*x[i]<=M) && (ymin*ymin+x[i]*x[i]<=M))
            return 1;
    }
    return 0;
}
LL sovle() {
    preMax[0] = -INF;
    preMin[0] = INF;
    for(int i=1;i<=n;i++) {
        preMax[i] = max(preMax[i-1], y[i]);
        preMin[i] = min(preMin[i-1], y[i]);
    }
    sufMax[n+1] = -INF;
    sufMin[n+1] = INF;
    for(int i=n;i>=1;i--) {
        sufMin[i] = min(sufMin[i+1], y[i]);
        sufMax[i] = max(sufMax[i+1], y[i]);
    }
    LL L = -1, R = 1e17;
    while (R - L > 1) {
        LL mid = (L+R)>>1;
        if (ok(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    LL ret = R;
    LL dx = *max_element(x+1,x+1+n) - *min_element(x+1,x+1+n); ret = min(ret, dx*dx);
    LL dy = *max_element(y+1,y+1+n) - *min_element(y+1,y+1+n); ret = min(ret, dy*dy);
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        p[i].read();
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
        x[i]=p[i].x;
        y[i]=p[i].y;
    }
    LL ans = sovle();
    for(int i=1;i<=n;i++) {
        p[i].x = -p[i].x;
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
        x[i]=p[i].x;
        y[i]=p[i].y;
    }
    ans = min(ans, sovle());
    cout << ans << endl;

}