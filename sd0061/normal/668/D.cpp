#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int M = 40000005;
int n;
unordered_map<int , int> c[N];
struct opt {
    int o , t , x;
}q[N];
int d[N] , D;
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int o , t , x;
        scanf("%d%d%d" , &o , &t , &x);
        q[i] = (opt) {o , t , x};
        d[D ++] = t;
    }
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (int i = 0 ; i < n ; ++ i) {
        int j = lower_bound(d , d + D , q[i].t) - d + 1;
        if (q[i].o < 3) {
            int w = q[i].o == 1 ? 1 : -1;
            for (int k = j ; k <= D ; k += k & -k) {
                c[k][q[i].x] += w;
            }
        } else {
            int res = 0;
            for (int k = j ; k > 0 ; k -= k & -k) {
                if (c[k].count(q[i].x)) {
                    res += c[k][q[i].x];
                }
            }
            printf("%d\n" , res);
        }

    }
}