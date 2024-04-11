#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(int n, int m, vector<int> a) {
    set<int> inRotation;
    int cap = n * m - 3;
    int cptr = 0;
    while (cptr < a.size() && inRotation.size() < cap) {
        inRotation.insert(a[cptr++]);
    }
    if (cptr == a.size()) return true;
    for (int i = (int)a.size() - 1; i >= 0 && cptr < a.size(); --i) {
        if (inRotation.count(i) == 0) return false;
        inRotation.erase(i);
        inRotation.insert(a[cptr++]);
    }
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m, k; scanf("%d %d %d", &n, &m, &k);
        vector<int> arr(k);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &arr[i]);
            --arr[i];
        }
        printf("%s\n", solve(n, m, arr) ? "YA" : "TIDAK");
    }
}