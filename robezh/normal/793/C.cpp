#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int N = (int)1e5 + 50;
const ld INF = 1e18, EPS = 1e-10;

int n;
int c1[2], c2[2];
int x[2][N], r[2][N];
ld mnt = 0, mxt = INF;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> c1[0] >> c1[1] >> c2[0] >> c2[1];
    for(int i = 0; i < n; i++) {
        cin >> x[0][i] >> x[1][i] >> r[0][i] >> r[1][i];
        for(int k = 0; k < 2; k++) {
            if(x[k][i] < c1[k] || x[k][i] > c2[k]) {
                if(x[k][i] < c1[k] && r[k][i] <= 0) return cout << "-1" << endl, 0;
                if(x[k][i] > c2[k] && r[k][i] >= 0) return cout << "-1" << endl, 0;
                ld t1 = (ld)(c1[k] - x[k][i]) / r[k][i], t2 = (ld)(c2[k] - x[k][i] ) / r[k][i];
                mnt = max(mnt, min(t1, t2));
                mxt = min(mxt, max(t1, t2));
            }
            else {
                if(r[k][i] != 0) {
                    ld t = r[k][i] > 0 ? (ld)(c2[k] - x[k][i]) / r[k][i] : (ld)(c1[k] - x[k][i]) / r[k][i];
                    mxt = min(mxt, t);
                }
            }

            if((x[k][i] == c1[k] || x[k][i] == c2[k]) && r[k][i] == 0) return cout << "-1" << endl, 0;
        }
    }
    if(mnt > mxt - EPS) return cout << "-1" << endl, 0;
    cout << fixed << setprecision(10) << mnt << endl;

}