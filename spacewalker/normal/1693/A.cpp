#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPossible(vector<ll> &arr) {
    // look for last nonzero element
    while (!arr.empty() && arr.back() == 0) arr.pop_back();
    if (arr.empty()) return true;
    while (arr.size() > 1) {
        if (arr.back() >= 0) return false;
        ll c = arr.back();
        arr.pop_back();
        arr.back() += c;
    }
    return arr[0] == 0;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> arr(n);
        for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
        if (isPossible(arr)) printf("yes\n");
        else printf("no\n");
    }
}