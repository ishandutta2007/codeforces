#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        printf("%s\n", (arr[0] == 1 ? "Yes" : "No"));
    }
}