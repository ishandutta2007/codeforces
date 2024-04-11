#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 2002;
LL ans = 0;
LL n;
struct Point {
    int x, y;
    void read() {
        scanf("%d%d",&x,&y);
    } 
} p[N];
vector<double> ang;
int main() {
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) p[i].read();
    for(int i=1;i<=n;i++) {
        ang.clear();
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            ang.push_back(atan2(p[j].x-p[i].x, p[j].y-p[i].y));
            ang.push_back(atan2(p[j].x-p[i].x, p[j].y-p[i].y) + 2*acos(-1));
        }
        sort(ang.begin(), ang.end());
        //printf("P(%d,%d)\n", p[i].x, p[i].y);
        //for(auto x: ang) printf("%.5f ", x); printf("\n");
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            double a1 = atan2(p[j].x-p[i].x, p[j].y-p[i].y);
            double a2 = a1 + acos(-1);
            LL c1 = 0, c2 = 0;
            c1 = lower_bound(ang.begin(), ang.end(), a2) - lower_bound(ang.begin(), ang.end(), a1+1e-10);
            c2 = n - c1 - 2;
            ans = ans + (c1*(c1-1)/2) *  (c2*(c2-1)/2);
            //printf("c1=%d, c2=%d, ans = %lld\n", c1,c2,ans);
        }
        //printf("%d\n", ans);
    }
    cout << ans/2 << endl;
}