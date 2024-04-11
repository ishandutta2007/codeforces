
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


bool solve(int n, int k, vector<ll> &psums) {
   if (k == 1) return true;
   vector<ll> asuf(k-1);
   for (int i = 0; i < asuf.size(); ++i) asuf[i] = psums[i+1] - psums[i];
   // check this suffix is nondec
   for (int i = 0; i + 1 < asuf.size(); ++i) if (asuf[i] > asuf[i+1]) return false;
   // check that we can achieve a sum of psums[0] using numbers at most asuf[0]
   return ((n - k + 1) * asuf[0] >= psums[0]);

}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        vector<ll> psums(k);
        for (int i = 0; i < k; ++i) scanf("%lld", &psums[i]);
        printf("%s\n", solve(n, k, psums) ? "YES" : "NO");
    }
}