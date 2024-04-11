#include <iostream>
#include <cmath>
using namespace std;
const int NICO = 100000+10;
typedef long long LL;
const double EPS = 1e-5;

int n, x, y;
int a[NICO];

bool isNearInt(double x) {
    int t = (int)(x + 0.5);
    if(abs(t - x) < 1e-8) return 1;
    return 0;
}

LL cac(LL t, LL blood) {
    LL cnt1 = t / y;
    LL cnt2 = t / x;
    return cnt1 + cnt2 - blood;
}

void solve(int blood) {

    LL L = 0, R = 1e17;
    while(R - L > 1) {
        LL mid = (L + R) / 2;
        if(cac(mid, (LL)blood) >= 0) {
            R = mid;
        } else {
            L = mid;
        }
    }
    if(cac(L, blood) >= 0) R = L;
    if(R % y == 0 && R % x == 0) printf("Both\n");
    else if(R % y == 0) printf("Vanya\n");
    else printf("Vova\n");


}

int main() {
    cin >> n >> x >> y;
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        solve(a[i]);
    }

}