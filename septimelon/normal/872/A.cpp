#include <bits/stdc++.h>

using namespace std;

void smin(int& x, int& y) {
    if (x > y) {
        swap(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bool> allow1(10, false);
    vector<bool> allow2(10, false);
    vector<int> allt(10, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (!allow1[a]) {
            allow1[a] = true;
            ++allt[a];
        }
    }
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        if (!allow2[a]) {
            allow2[a] = true;
            ++allt[a];
        }
    }
    for (int i = 1; i < 10; ++i) {
        if (allt[i] > 1) {
            cout << i << '\n';
            return 0;
        }
    }
    int m1, m2;
    for (int i = 0; i < 10; ++i) {
        if (allow1[i]) {
            m1 = i;
            break;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (allow2[i]) {
            m2 = i;
            break;
        }
    }
    smin(m1, m2);
    cout << m1 * 10 + m2 << '\n';

    return 0;
}