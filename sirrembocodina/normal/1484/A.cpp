#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int max_elem(vector<int> a) {
    int max = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
bool is_p_kv(int x) {
    int s = sqrt(x) + 0.5;
    if (s * s != x) {
        return false;
    } else {
        return true;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << n*m << endl;
    }
    return 0;
}