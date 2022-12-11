#include <bits/stdc++.h>
using namespace std;

#define scanf(a, b) assert(scanf(a, b) != -1)
#define TASKNAME "cactus"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 34;
const ll md = (ll)1e9 + 7;

int a[2][2], b[2][2];

int getr(int d1, int o1, int d2, int o2) {
    if (d1 > o2 && o1 > d2) return 1;
    if (d2 > o1 && o2 > d1) return -1;
    return 0;
}

int go(int df, int of) {
    int d2, o2;
    d2 = b[0][0];
    o2 = b[1][1];

    int r1 = getr(df, of, d2, o2);

    d2 = b[1][0];
    o2 = b[0][1];

    int r2 = getr(df, of, d2, o2);

    return min(r1, r2);
}

int main() {
    init();

    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> a[i][j];
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> b[i][j];

    int r1 = go(a[0][0], a[1][1]);
    int r2 = go(a[1][0], a[0][1]);

    int r = max(r1, r2);

    if (r == -1)
        cout << "Team 2";
    else if (r == 0)
        cout << "Draw";
    else
        cout << "Team 1";

    return 0;
}