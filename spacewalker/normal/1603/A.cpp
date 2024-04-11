#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    while (!arr.empty()) {
        bool removed = false;
        for (int i = int(arr.size()) - 1; i >= 0; --i) {
            if (arr[i] % (i + 2) == 0) continue;
            arr.erase(begin(arr) + i);
            removed = true;
            break;
        }
        if (!removed) return false;
    }
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%s\n", solve() ? "YES" : "NO"); 
    }
}