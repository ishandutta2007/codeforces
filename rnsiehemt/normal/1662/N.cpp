#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> order(N*N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int a;
            cin >> a;
            order[a-1] = {y, x};
        }
    }
    vector<int> yc(N), xc(N);
    long long ans = 0ll;
    for (auto [y, x] : order) {
        ans += (long long) yc[y] * (N-1 - xc[x]) + (long long) xc[x] * (N-1 - yc[y]);
        yc[y]++;
        xc[x]++;
    }
    cout << ans / 2 << endl;
}