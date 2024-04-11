#include <bits/stdc++.h>

using namespace std;
#define TASKNAME "cactus"
void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e9 + 34;

int n, m;
int a[555][555];
int c[555], r[555];

int main() {
    init();

    int mxr = -N, mnr = N, mxc = -N, mnc = N;

    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }

    if (n == 1) {
        //cout << sum << "\n";
        for (int j = 0; j < m; j++) {
            c[j] = a[0][j];
        }
        r[0] = 0;
    }

    if (m == 1) {
        //cout << sum << "\n";
        for (int i = 0; i < n; i++) {
            r[i] = a[i][0];
        }
        c[0] = 0;
    }

    if (max(n, m) > 1) {
        c[0] = 0;
        for (int i = 0; i < n; i++)
            r[i] = a[i][0];

        for (int j = 1; j < m; j++)
            for (int i = 0; i < n; i++) {
                c[j] = a[i][j] - r[i];
            }
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (a[i][j] != r[i] + c[j]) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        mnr = min(mnr, r[i]);
        mxr = max(mxr, r[i]);
    }

    for (int j = 0; j < m; j++) {
        mxc = max(mxc, c[j]);
        mnc = min(mnc, c[j]);
    }

    if (mnr + mnc < 0) {
        cout << "-1\n";
        return 0;
    }

    int dr = 0;
    int dc = 0;

    if (mnr < 0) {
        dc = mnr;
        dr = -dc;
    } else if (mnc < 0) {
        dr = mnc;
        dc = -dr;
    }

    while (n > m && mnr + dr > 0) {
        dr--;
        dc++;
    }

    while (n < m && mnc + dc > 0) {
        dr++;
        dc--;
    }

    int num = 0;
    for (int i = 0; i < n; i++)
        num += r[i] + dr;
    for (int j = 0; j < m; j++)
        num += c[j] + dc;

    cout << num << "\n";

    for (int i = 0; i < n; i++) {
        //cout << r[i] << " " << dr << "\n";
        for (int j = 0; j < r[i] + dr; j++)
            cout << "row " << i + 1 << "\n";
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < c[j] + dc; i++)
            cout << "col " << j + 1 << "\n";
    }

    return 0;
}