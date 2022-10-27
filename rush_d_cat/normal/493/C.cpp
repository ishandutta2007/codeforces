#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

vector<LL> a, b, c;
LL n, m, x;

int main() {
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &x); a.push_back(x); c.push_back(x);c.push_back(x+1);
    }

    scanf("%lld", &m);
    for(int i=1;i<=m;i++) {
        scanf("%lld", &x); b.push_back(x); c.push_back(x);c.push_back(x+1);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    c.push_back(1e16);

    LL dmax = -1e16, point_a = 0, point_b = 0;

    LL cnt_a = a.size(), cnt_b = b.size();

    for(int i=0;i<c.size();i++) {
        int ca = lower_bound(a.begin(), a.end(), c[i]) - a.begin();
        //printf(">= %lld ", c[i]);
        LL pa = ca * 2 + (cnt_a - ca) * 3;

        int cb = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
        LL pb = cb * 2 + (cnt_b - cb) * 3;
        //printf("%lld : %lld\n", pa, pb);
        //printf("c:%lld pa:%lld pb:%lld\n", c[i], pa, pb);
        if(pa - pb >= dmax) {
            if(pa - pb > dmax) dmax=pa-pb, point_a=pa, point_b=pb;
            if(pa - pb ==dmax && pa > point_a) point_a=pa, point_b=pb;
        }
    }
    printf("%lld:%lld\n", point_a, point_b);

}