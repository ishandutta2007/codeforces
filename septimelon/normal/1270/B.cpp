#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxa = 0, mina = 1000000000;
    int maxi, mini;
    bool comp = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --maxa;
        ++mina;
        if (a[i] > maxa) {
            maxa = a[i];
            maxi = i;
        }
        if (a[i] < mina) {
            mina = a[i];
            mini = i;
        }
        if (maxa > mina && !comp) {
            cout << "YES\n" << min(mini, maxi) + 1 << " " << max(maxi, mini) + 1 << '\n';
            comp = true;
        }
    }
    if (!comp) {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}