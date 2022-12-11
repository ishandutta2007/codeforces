#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve_brute(vector<int> &arr) {
    vector<int> pseq;
    for (int i = 0; i < arr.size(); ++i) {
        for (int k = 0; k < abs(arr[i]); ++k) pseq.push_back(i % 2 == 0 ? 1 : -1);
    }
    ll ans = 0;
    for (int i = 0; i < pseq.size(); ++i) {
        ll bal = 0, rmin = 0;
        for (int j = i; j < pseq.size(); ++j) {
            bal += pseq[j];
            rmin = min(rmin, bal);
            if (bal == 0 && rmin >= 0) ++ans;
        }
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    /*
    srand(time(NULL));
    int n = 20;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = rand() % 50 + 1;
    fprintf(stderr, "!! arr ");
    for (int i = 0; i < n; ++i) fprintf(stderr, "%d ", arr[i]);
    fprintf(stderr, "\n");
    */
    for (int i = 1; i < n; i += 2) arr[i] *= -1;
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ll rdelta = 0, rmin = 0;
        for (int j = i + 1; j < n; ++j) {
            if (j % 2 == 1) {
                ll leftUse = arr[i], rightUse = -arr[j];
                leftUse += rmin;
                if (rdelta - rmin > 0) rightUse -= rdelta - rmin;
                else leftUse += rdelta - rmin;
                ll ccontrib = max(0LL, min(leftUse, rightUse) + (j > i + 1));
                ans += ccontrib;
//                printf("%d %d %lld u %lld %lld\n", i, j, ccontrib, leftUse, rightUse);
            }
            rdelta += arr[j];
            rmin = min(rmin, rdelta);
        }
    }
//    assert(ans == solve_brute(arr));
    printf("%lld\n", ans);
}