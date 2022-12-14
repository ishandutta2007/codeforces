#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        int mL, mR, cL, cR, tL, tR, cs;
        cin >> mL >> mR >> cs;
        tL = mL;
        tR = mR;
        cL = cR = cs;
        cout << cs << "\n";
        for (int i = 1; i < n; i += 1) {
            int L, R, c;
            cin >> L >> R >> c;
            if (L < mL) mL = L, cL = INT_MAX;
            if (L == mL) cL = min(cL, c);
            if (R > mR) mR = R, cR = INT_MAX;
            if (R == mR) cR = min(cR, c);
            if (L == mL and R == mR) {
                if (tL != L or tR != R) cs = INT_MAX;
                tL = L;
                tR = R;
                cs = min(cs, c);
            }
            cout << min(cL + cR, tL == mL and tR == mR ? cs : INT_MAX) << "\n";
        }
    }
    return 0;
}