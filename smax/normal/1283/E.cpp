#include <bits/stdc++.h>
using namespace std;

int cnt[200001] = {};
bool covered[200002] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int mn = 0;
    for (int i=1; i<=n; i++)
        if (cnt[i]) {
            mn++;
            i += 2;
        }

    int mx = 0;
    for (int i=1; i<=n; i++) {
        if (cnt[i] && !covered[i-1]) {
            mx++;
            cnt[i]--;
            covered[i-1] = true;
        }
        if (cnt[i] && !covered[i]) {
            mx++;
            cnt[i]--;
            covered[i] = true;
        }
        if (cnt[i] && !covered[i+1]) {
            mx++;
            cnt[i]--;
            covered[i+1] = true;
        }
    }

    cout << mn << " " << mx << "\n";

    return 0;
}