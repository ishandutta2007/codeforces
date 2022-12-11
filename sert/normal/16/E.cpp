#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef double ld;
const int N = 18;
ld a[N][N];
ld p[1 << N][N], ans;
bool u[1 << N];
int n;

void go(int mask) {
    if (u[mask]) return;
    u[mask] = true;
    for (int i = 0; i < n; i++)
        if (mask == (1 << i)) {
            p[mask][i] = 1.0;
            return;
        }
    vector <int> dt;
    dt.clear();
    for (int i = 0; i < n; i++)
        if ((mask | (1 << i)) == mask)
            dt.push_back(i);
    ld sum = 0.0;
    for (int i = 0; i < dt.size(); i++)
    for (int j = 0; j < dt.size(); j++) {
        if (i == j) continue;
        go(mask ^ (1 << dt[j]));
        for (int ii = 0; ii < n; ii++)
            p[mask][ii] += p[mask ^ (1 << dt[j])][ii] * a[dt[i]][dt[j]];
    }

    for (int i = 0; i < n; i++) sum += p[mask][i];
    //cerr << sum << "\n";
    for (int i = 0; i < n; i++) p[mask][i] /= sum;
    return;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    go((1 << n) - 1);
    cout.precision(10);
    for (int i = 0; i < n; i++)
        cout << fixed << p[(1 << n) - 1][i] << " ";
    return 0;
}