#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 1; i < n; i += 2) {
        b[i] = a[i / 2];
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            b[n - i - 2] = a[n / 2 + i / 2];
        }
    }
    else {
        for (int i = 0; i < n; i += 2) {
            b[n - i - 1] = a[n / 2 + i / 2];
        }
    }

    int ans = 0;
    for (int i = 1; i + 1 < n; i += 2) {
        if (b[i - 1] > b[i] && b[i + 1] > b[i]) {
            ++ans;
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }

    return 0;
}