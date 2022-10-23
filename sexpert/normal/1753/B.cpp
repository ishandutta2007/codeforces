#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;
int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;
        cnt[y]++;
    }

    for(int m = 1; m + 1 <= x; m++) {
        cnt[m + 1] += (cnt[m] / (m + 1));
        cnt[m] %= (m + 1);
        if(cnt[m] > 0) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}