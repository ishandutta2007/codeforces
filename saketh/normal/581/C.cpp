#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, K;
    cin >> N >> K;

    int ans = 0;

    vector<int> buy;
    for (int i = 0; i < N; i++) {
        int sk;
        cin >> sk;

        ans += sk / 10;
        buy.push_back(10 - (sk % 10));
    }

    sort(buy.begin(), buy.end());

    for (int v : buy) {
        if(v > K) break;
        ans++;
        K -= v;
    }

    ans += K / 10;
    int lim = 10 * N;
    cout << min(ans, lim) << endl;
}