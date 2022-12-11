#include <bits/stdc++.h>

using namespace std;

bool subsolve(vector<int> &v, int x) {
    vector<int> w;
    for (int y : v) if (y != x) w.push_back(y);
    for (int i = 0, j = int(w.size() - 1); i < j; ++i, --j) {
        if (w[i] != w[j]) return false;
    } return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int st = 0, ed = n - 1;
        while (st <= ed && arr[st] == arr[ed]) ++st, --ed;
        if (st > ed) printf("YES\n");
        else {
//            printf("subcase %d %d\n", st, ed);
            vector<int> rarr = arr;
            if (subsolve(rarr, arr[st]) || subsolve(rarr, arr[ed])) printf("yes\n");
            else printf("no\n");
        }
    }
}