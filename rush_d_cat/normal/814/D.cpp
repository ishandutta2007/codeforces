#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-6;
double x[1002], y[1002], r[1002], dis;
int n, cnt[1002];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(i == j) {
                continue;
            }

            dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if((r[i]-r[j]) * (r[i]-r[j]) + 1e-7 > dis) {
                if(r[i] > r[j]) cnt[j] ++;
                if(r[j] > r[i]) cnt[i] ++;
            }
        }
    }

    double ans = 0;
    for(int i=1;i<=n;i++) {
        if(cnt[i] == 1 || cnt[i] == 0) ans += PI*r[i]*r[i];
        else if(cnt[i] % 2 == 0) ans -= PI*r[i]*r[i];
        else {
            ans += PI*r[i]*r[i];
        }
    }
    printf("%.12f\n", ans);
}