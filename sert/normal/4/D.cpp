#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 34;
int n, ww, hh, w[N], h[N], p[N], a[N], mx;
vector <int> v;
bool u[N];
int cnt(int num) {
    if (u[num])
        return a[num];
    if (w[num] <= ww || h[num] <= hh)
        return 0;
    u[num] = true;
    int ans = 0, ps = -1, q;
    for (int i = 0; i < n; i++)
        if (w[i] < w[num] && h[i] < h[num] && w[num] > ww && h[num] > hh) {
            q = cnt(i);
            if (q > ans) {
                ps = i;
                ans = a[i];
            }
        }
    p[num] = ps;
    return a[num] = ans + 1;
}
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> ww >> hh;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
        p[i] = -1;
    }
    for (int i = 0; i < n; i++)
        cnt(i);
    mx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > a[mx])
            mx = i;
    if (a[mx] == 0) {
        cout << 0;
        return 0;
    }
    cout << a[mx] << "\n";
    while (mx != -1) {
        v.push_back(mx + 1);
        mx = p[mx];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}