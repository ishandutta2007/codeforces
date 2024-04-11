#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int x[10], y[10];

int main() {
    int mx = INF, Mx = -INF, my = INF, My = -INF, ma = INF, Ma = -INF, mb = INF, Mb = -INF;
    for(int i = 0; i < 8; i++) {
        cin >> x[i] >> y[i];
        x[i] *= 2;
        y[i] *= 2;
        if(i < 4) {
            mx = min(mx, x[i]);
            Mx = max(Mx, x[i]);
            my = min(my, y[i]);
            My = max(My, y[i]);
        }
        else {
            ma = min(ma, x[i] + y[i]);
            Ma = max(Ma, x[i] + y[i]);
            mb = min(mb, x[i] - y[i]);
            Mb = max(Mb, x[i] - y[i]);
        }
    }
    x[8] = (x[0] + x[1] + x[2] + x[3])/4;
    y[8] = (y[0] + y[1] + y[2] + y[3])/4;
    x[9] = (x[4] + x[5] + x[6] + x[7])/4;
    y[9] = (y[4] + y[5] + y[6] + y[7])/4;
    for(int i = 0; i < 10; i++) {
        if((i == 8 || i < 4) && x[i] + y[i] >= ma && x[i] + y[i] <= Ma && x[i] - y[i] >= mb && x[i] - y[i] <= Mb) {
            cout << "YES\n";
            return 0;
        }
    }
    for(int i = 4; i < 10; i++) {
        if((i == 9 || i < 8) && x[i] >= mx && x[i] <= Mx && y[i] >= my && y[i] <= My) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}