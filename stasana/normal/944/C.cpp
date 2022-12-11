#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    vector<int> h(n);
    h[0] = 0;
    cnt[0] = 1;
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        h[i] = h[v - 1] + 1;
        ++cnt[h[i]];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += cnt[i] % 2;
    }
    cout << res;
    return 0;
}