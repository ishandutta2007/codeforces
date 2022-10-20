#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    long long ans = n;
    for (int i = 0; i < n; ++i) {
        ans += max(l[i], r[i]);
    }
    cout << ans << "\n";
    return 0;
}