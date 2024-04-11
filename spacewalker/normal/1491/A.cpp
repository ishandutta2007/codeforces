#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; scanf("%d %d", &n, &q);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int oc = 0;
    for (int x : arr) if (x == 1) ++oc;
    for (int qta = 0; qta < q; ++qta) {
        int t, p; scanf("%d %d", &t, &p);
        if (t == 1) {
            --p;
            if (arr[p] == 1) --oc;
            else ++oc;
            arr[p] = 1 - arr[p];
        } else {
            printf("%d\n", oc >= p ? 1 :  0);
        }
    }
}