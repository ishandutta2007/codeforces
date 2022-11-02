#include <bits/stdc++.h>

using namespace std;

long long ans = -1;
long long a1, t1, p1, a2, t2, p2;
long long f, T, t0;

void inline update(long long P1, long long P2) {
    long long P0 = max(0LL, f - P1 * a1 - P2 * a2);
    long long v = P1 * p1 + P2 * p2;
    long long tt = P0 * t0 + P1 * a1 * t1 + P2 * a2 * t2;
    if (P0 == 0) {
        if (P1 * a1 + P2 * a2 > f) {
            long long rf = P1 * a1 + P2 * a2 - f;
            long long tt1 = tt;
            if (P1 * a1 >= rf) tt1 -= rf * t1;
            long long tt2 = tt;
            if (P2 * a2 >= rf) tt2 -= rf * t2;
            tt = min(tt1, tt2);
        }
    }
    if (tt <= T)
       ans = (ans == -1) ? v : min(ans, v);
}

int main() {
    
    cin >> f >> T >> t0;
    cin >> a1 >> t1 >> p1;
    cin >> a2 >> t2 >> p2;
    
    long long P1;
    for (P1 = 0; P1 * a1 <= f; ++P1) {
        long long rf = f - P1 * a1;
        long long rt = T - P1 * a1 * t1;
        //Case where over fit
        update(P1, (rf + a2 - 1) / a2);
        //Case where none
        update(P1, 0);
        //Otherwise
        if (t2 < t0) {
            //min b s.t. b * t2 + (rf - b) * t0 <= rt
            //           b * (t2 - t0) <= rt - rf * t0
            //           b * (t0 - t2) >= rf * t0 - rt
            long long b = (rf * t0 - rt + t0 - t2 - 1) / (t0 - t2);
            if (b <= rf && b >= 0) {
               long long P2 = (b + a2 - 1) / a2;
               update(P1, P2);
            }
        }
    }
    
    if (P1 * t1 <= T) update(P1, 0);

    long long P2;
    for (P2 = 0; P2 * a2 <= f; ++P2) {
        long long rf = f - P2 * a2;
        long long rt = T - P2 * a2 * t2;
        //Case where over fit
        update((rf + a1 - 1) / a1, P2);
        //Case where none
        update(0, P2);
        //Otherwise
        if (t1 < t0) {
            long long b = (rf * t0 - rt + t0 - t1 - 1) / (t0 - t1);
            if (b <= rf && b >= 0) {
               long long P1 = (b + a1 - 1) / a1;
               update(P1, P2);
            }
        }
    }

    if (P2 * t2 <= T) update(0, P2);
    
    cout << ans << endl;
    
    return 0;
}