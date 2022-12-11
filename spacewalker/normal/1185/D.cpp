#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isArith(vector<pair<ll, int>> arr) {
    sort(begin(arr), end(arr));
    if (arr.size() < 3) return true;
    ll d = arr[1].first - arr[0].first;
    for (int i = 2; i < arr.size(); ++i) if (arr[i].first - arr[i-1].first != d) return false;
    return true;
}

int solve() {
    int n; scanf("%d", &n);
    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].second = i;
        scanf("%lld", &arr[i].first);
    }
    sort(begin(arr), end(arr));
    if (n <= 3) {
        return 1;
    }
    vector<pair<ll, int>> exFirst(begin(arr) + 1, end(arr)), exLast(begin(arr), end(arr) - 1);
    if (isArith(exFirst)) {
        return arr[0].second + 1;
    } else if (isArith(exLast)) {
        return arr[n-1].second + 1;
    } else {
        vector<pair<ll, int>> mismatches;
        if ((arr[n-1].first - arr[0].first) % (n - 2) != 0) {
            return -1;
        }
        ll d = (arr[n-1].first - arr[0].first) / (n-2);
        for (int i = 0; i < n; ++i) {
            ll cval = arr[0].first + (i - (int)mismatches.size()) * d;
            if (cval != arr[i].first) {
                mismatches.push_back(arr[i]);
            }
        }
        if (mismatches.size() != 1) return -1;
        else return mismatches[0].second + 1;
    }
}

int main() {
    printf("%d\n", solve());
}