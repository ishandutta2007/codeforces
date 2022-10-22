#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> u(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (!u[i]) {
            ans++;
            for (int j = i + 1; j < n; j++) {
                if (a[j] % a[i] == 0)
                    u[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}