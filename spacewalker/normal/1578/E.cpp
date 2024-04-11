#include <bits/stdc++.h>

using namespace std;

bool isComposite(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

void solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int allsum = 0;
    for (int v : arr) allsum += v;
    vector<int> ans;
    if (isComposite(allsum)) {
        for (int i = 0; i < n; ++i) ans.push_back(i); 
    } else {
        int oddKeep = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 0) {
                ans.push_back(i);
            } else {
                ++oddKeep;
                if (oddKeep > 1) ans.push_back(i);
            }
        } 
    }
    printf("%lu\n", ans.size());
    for (int v : ans) printf("%d ", v + 1);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}