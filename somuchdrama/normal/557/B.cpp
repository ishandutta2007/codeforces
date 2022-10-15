#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    double n;
    double w;
    cin >> n >> w;
    vector<double> A(2 * (int)n);
    for(int i = 0; i < 2 * n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    double ans = w;
    ans = min(ans, A[0] * 3 * n);
    ans = min(ans, A[n] * n * 1.5);
    cout << fixed;
    cout.precision(8);
    cout << ans;
    return 0;
}